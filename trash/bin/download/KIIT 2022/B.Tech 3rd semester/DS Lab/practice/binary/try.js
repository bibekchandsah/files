// Create a button
const button = document.createElement('button');
button.innerHTML = 'PIP';
button.style.cssText = 'position: absolute; right: 40%; bottom: 1.5%; transform: translateY(-50%); background: gray; border-radius: 50%; padding: 8px; cursor: pointer; margin-right: 0;';
document.body.appendChild(button);

// Add event listener to the button
button.addEventListener('click', function () {
    updateVideoAttributes();
});

// Function to update video attributes
function updateVideoAttributes() {
    const videos = document.querySelectorAll('video');

    videos.forEach(video => {
        video.removeAttribute('disablepictureinpicture');
        video.setAttribute('disablepictureinpicturee', '');
    });
}