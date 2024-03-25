// ==UserScript==
// @name         Google Form Enhancer
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  Enhance Google Forms functionality.
// @author       Your Name
// @match        https://docs.google.com/forms/*
// @icon         https://www.gstatic.com/images/branding/product/1x/forms_2020q4_48dp.png
// @grant        none
// ==/UserScript==

(function () {
    'use strict';

    // Wait for the page to load completely
    window.addEventListener('load', function () {
        enhanceGoogleForm();
    });

    function enhanceGoogleForm() {
        var M7eMeElements = document.querySelectorAll(".M7eMe");

        M7eMeElements.forEach(function (M7eMe) {
            var text = M7eMe.innerText;
            var optionsElement = M7eMe.closest(".freebirdFormviewerComponentsQuestionBaseHeader");
            var options = optionsElement ? optionsElement.innerText : "";

            // Create SEARCH and COPY links
            var searchLink = document.createElement('a');
            searchLink.href = 'https://www.google.com/search?q=' + encodeURIComponent(text);
            searchLink.target = '_blank';
            searchLink.textContent = 'SEARCH';

            var copyLink = document.createElement('a');
            copyLink.href = 'javascript:void(0);';
            copyLink.textContent = 'COPY';
            copyLink.onclick = function () {
                copyTextToClipboard(text + ' ' + options);
            };

            // Create a container for the links
            var linkContainer = document.createElement('div');
            linkContainer.appendChild(searchLink);
            linkContainer.appendChild(document.createTextNode(' '));
            linkContainer.appendChild(copyLink);

            // Insert the link container below the .M7eMe element
            M7eMe.parentNode.insertBefore(linkContainer, M7eMe.nextSibling);
        });
    }

    function copyTextToClipboard(text) {
        var textArea = document.createElement("textarea");
        textArea.value = text;
        document.body.appendChild(textArea);
        textArea.select();
        document.execCommand("copy");
        document.body.removeChild(textArea);
    }
})();
