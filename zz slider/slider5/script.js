document.addEventListener('DOMContentLoaded', () => {
  // Elements
  const track = document.querySelector('.carousel-track');
  const items = document.querySelectorAll('.carousel-item');
  const prevButton = document.querySelector('.nav-button.prev');
  const nextButton = document.querySelector('.nav-button.next');
  const thumbnails = document.querySelectorAll('.thumbnail');
  const progressBar = document.querySelector('.progress-bar');
  const currentCounter = document.querySelector('.current');
  const totalCounter = document.querySelector('.total');
  
  // Variables
  let currentIndex = 0;
  const itemCount = items.length;
  let autoplayInterval;
  const autoplayDelay = 6000; // 6 seconds
  let animating = false;
  
  // Initialize counter
  totalCounter.textContent = itemCount.toString().padStart(2, '0');
  updateCounter();
  
  // Functions
  function updateCarousel(animate = true) {
    if (animating) return;
    
    animating = true;
    
    // Update track position
    track.style.transform = `translateX(-${currentIndex * 100}%)`;
    
    // Update thumbnails
    thumbnails.forEach((thumb, index) => {
      thumb.classList.toggle('active', index === currentIndex);
    });
    
    // Update counter
    updateCounter();
    
    // Reset progress bar
    resetProgressBar();
    
    // Add animation classes to current slide content
    if (animate) {
      const currentItem = items[currentIndex];
      const title = currentItem.querySelector('.item-title');
      const excerpt = currentItem.querySelector('.item-excerpt');
      const meta = currentItem.querySelector('.item-meta');
      const readMore = currentItem.querySelector('.read-more');
      
      // Remove existing animation classes from all items
      document.querySelectorAll('.item-title, .item-excerpt, .item-meta, .read-more').forEach(el => {
        el.classList.remove('fade-in', 'slide-up');
      });
      
      // Add animation with delay
      setTimeout(() => {
        title.classList.add('slide-up');
        
        setTimeout(() => {
          excerpt.classList.add('slide-up');
          
          setTimeout(() => {
            meta.classList.add('fade-in');
            readMore.classList.add('fade-in');
            
            // Animation complete
            animating = false;
          }, 100);
        }, 100);
      }, 300);
    } else {
      animating = false;
    }
  }
  
  function updateCounter() {
    currentCounter.textContent = (currentIndex + 1).toString().padStart(2, '0');
  }
  
  function goToSlide(index, animate = true) {
    currentIndex = index;
    updateCarousel(animate);
    resetAutoplay();
  }
  
  function goToNextSlide() {
    if (animating) return;
    currentIndex = (currentIndex + 1) % itemCount;
    updateCarousel();
    resetAutoplay();
  }
  
  function goToPrevSlide() {
    if (animating) return;
    currentIndex = (currentIndex - 1 + itemCount) % itemCount;
    updateCarousel();
    resetAutoplay();
  }
  
  function startAutoplay() {
    autoplayInterval = setInterval(goToNextSlide, autoplayDelay);
    startProgressBar();
  }
  
  function resetAutoplay() {
    clearInterval(autoplayInterval);
    startAutoplay();
  }
  
  function pauseAutoplay() {
    clearInterval(autoplayInterval);
    pauseProgressBar();
  }
  
  function startProgressBar() {
    progressBar.style.transition = `width ${autoplayDelay}ms linear`;
    progressBar.style.width = '100%';
  }
  
  function resetProgressBar() {
    progressBar.style.transition = 'none';
    progressBar.style.width = '0';
    // Force reflow
    void progressBar.offsetWidth;
    startProgressBar();
  }
  
  function pauseProgressBar() {
    const computedStyle = window.getComputedStyle(progressBar);
    const width = computedStyle.getPropertyValue('width');
    progressBar.style.transition = 'none';
    progressBar.style.width = width;
  }
  
  // Event listeners
  nextButton.addEventListener('click', () => {
    if (!animating) goToNextSlide();
  });
  
  prevButton.addEventListener('click', () => {
    if (!animating) goToPrevSlide();
  });
  
  // Thumbnail navigation
  thumbnails.forEach((thumbnail, index) => {
    thumbnail.addEventListener('click', () => {
      if (currentIndex !== index && !animating) {
        goToSlide(index);
      }
    });
  });
  
  // Touch events for mobile swipe
  let touchStartX = 0;
  let touchEndX = 0;
  
  track.addEventListener('touchstart', (e) => {
    touchStartX = e.changedTouches[0].screenX;
    pauseAutoplay();
  }, { passive: true });
  
  track.addEventListener('touchend', (e) => {
    touchEndX = e.changedTouches[0].screenX;
    handleSwipe();
    startAutoplay();
  }, { passive: true });
  
  function handleSwipe() {
    const swipeThreshold = 50;
    if (touchStartX - touchEndX > swipeThreshold) {
      // Swipe left, go to next slide
      goToNextSlide();
    } else if (touchEndX - touchStartX > swipeThreshold) {
      // Swipe right, go to previous slide
      goToPrevSlide();
    }
  }
  
  // Pause autoplay on hover
  track.addEventListener('mouseenter', pauseAutoplay);
  track.addEventListener('mouseleave', startAutoplay);
  
  // Keyboard navigation
  document.addEventListener('keydown', (e) => {
    if (e.key === 'ArrowLeft') {
      goToPrevSlide();
    } else if (e.key === 'ArrowRight') {
      goToNextSlide();
    }
  });
  
  // Video play functionality
  const videoIndicators = document.querySelectorAll('.video-indicator');
  videoIndicators.forEach(indicator => {
    indicator.addEventListener('click', (e) => {
      e.stopPropagation();
      // Here you would typically launch a video modal
      // For this example, we'll just show an alert
      alert('Video would play here in a real implementation');
    });
  });
  
  // Initialize animations for first slide
  const initialItem = items[0];
  const initialTitle = initialItem.querySelector('.item-title');
  const initialExcerpt = initialItem.querySelector('.item-excerpt');
  const initialMeta = initialItem.querySelector('.item-meta');
  const initialReadMore = initialItem.querySelector('.read-more');
  
  setTimeout(() => {
    initialTitle.classList.add('slide-up');
    
    setTimeout(() => {
      initialExcerpt.classList.add('slide-up');
      
      setTimeout(() => {
        initialMeta.classList.add('fade-in');
        initialReadMore.classList.add('fade-in');
      }, 100);
    }, 100);
  }, 300);
  
  // Handle visibility change (pause when tab is not active)
  document.addEventListener('visibilitychange', () => {
    if (document.hidden) {
      pauseAutoplay();
    } else {
      startAutoplay();
    }
  });
  
  // Start autoplay
  startAutoplay();
  
  // Preload images for smoother transitions
  function preloadImages() {
    items.forEach(item => {
      const img = item.querySelector('img');
      const src = img.getAttribute('src');
      if (src) {
        const preloadImg = new Image();
        preloadImg.src = src;
      }
    });
  }
  
  preloadImages();
});
