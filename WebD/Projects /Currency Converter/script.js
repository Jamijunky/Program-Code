// API endpoint for currency data
const API_URL = 'https://api.exchangerate-api.com/v4/latest/USD';

// DOM elements
const amountInput = document.getElementById('amount');
const fromCurrencySelect = document.getElementById('from-currency');
const toCurrencySelect = document.getElementById('to-currency');
const resultDisplay = document.querySelector('.result');
const form = document.getElementById('currency-form');

// Global variables
let currencyData = {};

// Fetch currency data when page loads
document.addEventListener('DOMContentLoaded', async () => {
    try {
        // Show loading state
        resultDisplay.textContent = 'Loading currency data...';
        
        // Fetch the latest exchange rates
        const response = await fetch(API_URL);
        const data = await response.json();
        
        if (!response.ok) {
            throw new Error('Failed to fetch currency data');
        }
        
        currencyData = data;
        
        // Populate currency dropdowns
        populateCurrencyDropdowns(data.rates);
        
        // Set default values
        fromCurrencySelect.value = 'USD';
        toCurrencySelect.value = 'EUR';
        
        resultDisplay.textContent = 'Conversion result will appear here';
    } catch (error) {
        console.error('Error:', error);
        resultDisplay.textContent = 'Error loading currency data. Please try again later.';
    }
});

// Populate currency dropdowns with available currencies
function populateCurrencyDropdowns(rates) {
    // Get all currency codes and sort alphabetically
    const currencies = Object.keys(rates).sort();
    
    // Add USD (base currency) if not already in the list
    if (!currencies.includes('USD')) {
        currencies.unshift('USD');
    }
    
    // Clear existing options
    fromCurrencySelect.innerHTML = '';
    toCurrencySelect.innerHTML = '';
    
    // Add currency options to both dropdowns
    currencies.forEach(currency => {
        const fromOption = document.createElement('option');
        fromOption.value = currency;
        fromOption.textContent = currency;
        
        const toOption = document.createElement('option');
        toOption.value = currency;
        toOption.textContent = currency;
        
        fromCurrencySelect.appendChild(fromOption);
        toCurrencySelect.appendChild(toOption);
    });
}

// Handle form submission for currency conversion
form.addEventListener('submit', e => {
    e.preventDefault();
    convertCurrency();
});

// Convert currency based on user input
function convertCurrency() {
    // Get user input values
    const amount = parseFloat(amountInput.value);
    const fromCurrency = fromCurrencySelect.value;
    const toCurrency = toCurrencySelect.value;
    
    // Validate input
    if (isNaN(amount) || amount <= 0) {
        resultDisplay.textContent = 'Please enter a valid amount';
        return;
    }
    
    try {
        // Get exchange rates
        const fromRate = fromCurrency === 'USD' ? 1 : currencyData.rates[fromCurrency];
        const toRate = toCurrency === 'USD' ? 1 : currencyData.rates[toCurrency];
        
        // Calculate conversion
        const convertedAmount = (amount / fromRate) * toRate;
        
        // Format the result with 2 decimal places
        const formattedResult = convertedAmount.toFixed(2);
        
        // Display the result
        resultDisplay.innerHTML = `
            <span>${amount} ${fromCurrency} = </span>
            <span style="color: #0ff; font-weight: bold; font-size: 1.2em;">${formattedResult} ${toCurrency}</span>
        `;
    } catch (error) {
        console.error('Conversion error:', error);
        resultDisplay.textContent = 'Error during conversion. Please try again.';
    }
}

// Swap the selected currencies
function swapCurrencies() {
    const tempCurrency = fromCurrencySelect.value;
    fromCurrencySelect.value = toCurrencySelect.value;
    toCurrencySelect.value = tempCurrency;
    
    // If there's an amount entered, perform conversion with the swapped currencies
    if (amountInput.value && amountInput.value > 0) {
        convertCurrency();
    }
}