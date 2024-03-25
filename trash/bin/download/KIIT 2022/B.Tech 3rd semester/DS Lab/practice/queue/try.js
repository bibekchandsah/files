// ==UserScript==
// @name         New Userscript
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  try to take over the world!
// @author       You
// @match        https://docs.google.com/forms/u/0/*
// @icon         https://www.gstatic.com/images/branding/product/1x/forms_2020q4_48dp.png
// @grant        none
// ==/UserScript==

(function () {
    'use strict';

    M.cfg.developerdebug = true;
    var myContent = [...document.querySelectorAll(".content")];
    myContent.pop();

    myContent.forEach((element) => {
        if (element.querySelector(".M7eMe") == null) {
            return;
        }

        let text = element.querySelector(".M7eMe").textContent;
        let options = element.querySelector(".aDTYNe snByac OvPDhc OIC90c").textContent.replaceAll("\n", "");
        element.innerHTML += `<a href='https://google.com/search?q=${text}' target='_blank'>SEARCH</a>`
        element.innerHTML += `&nbsp;&nbsp;&nbsp;&nbsp;<a href="#" onclick="navigator.clipboard.writeText('${text + options}')">COPY</a>`
    });
})();