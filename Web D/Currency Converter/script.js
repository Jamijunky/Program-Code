const currencyForm = document.getElementById("currency-form");
const amountInput = document.getElementById("amount");
const fromCurrency = document.getElementById("from-currency");
const toCurrency = document.getElementById("to-currency");
const resultText = document.querySelector(".result");

// API Key (Replace with your own)
const API_KEY = "your-api-key";
const API_URL = `https://v6.exchangerate-api.com/v6/${API_KEY}/latest/`;

// Populate currency dropdowns dynamically
const currencyList = ["USD", "EUR", "INR", "GBP", "JPY", "CAD", "AUD", "CNY", "BTC"];
currencyList.forEach(currency => {
    fromCurrency.innerHTML += `<option value="${currency}">${currency}</option>`;
    toCurrency.innerHTML += `<option value="${currency}">${currency}</option>`;
});

fromCurrency.value = "USD";
toCurrency.value = "INR";

// Swap function with animation
function swapCurrencies() {
    fromCurrency.classList.add("swap-animation");
    toCurrency.classList.add("swap-animation");

    setTimeout(() => {
        [fromCurrency.value, toCurrency.value] = [toCurrency.value, fromCurrency.value];
        fromCurrency.classList.remove("swap-animation");
        toCurrency.classList.remove("swap-animation");
    }, 300);
}

// Fetch exchange rates and convert currency
async function convertCurrency(amount, from, to) {
    try {
        const response = await fetch(`${API_URL}${from}`);
        const data = await response.json();
        const rate = data.conversion_rates[to];

        if (!rate) {
            resultText.textContent = "Conversion rate not available.";
            return;
        }

        const convertedAmount = (amount * rate).toFixed(2);
        resultText.innerHTML = `🎯 ${amount} ${from} = <strong>${convertedAmount} ${to}</strong>`;
    } catch (error) {
        resultText.textContent = "Error fetching exchange rates. Try again!";
    }
}

// Handle form submission
currencyForm.addEventListener("submit", (e) => {
    e.preventDefault();
    const amount = parseFloat(amountInput.value);

    if (!amount || amount <= 0) {
        resultText.textContent = "Enter a valid amount!";
        return;
    }

    convertCurrency(amount, fromCurrency.value, toCurrency.value);
});
