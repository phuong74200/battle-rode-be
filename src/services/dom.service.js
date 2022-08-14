const puppeteer = require('puppeteer');
const DOMPurify = require('isomorphic-dompurify');

const capture = async (html) => {
    const browser = await puppeteer.launch({ args: ['--no-sandbox', '--disable-setuid-sandbox'] });
    const page = await browser.newPage();

    page.setViewport({ width: 400, height: 300 });

    await page.setRequestInterception(true);
    page.on('request', (request) => {
        request.abort();
    });

    await page.setContent(html);

    const imageBuffer = await page.screenshot({ omitBackground: false });

    await page.close();
    await browser.close();

    return imageBuffer;
};

const purify = (html) => {
    return DOMPurify.sanitize(html, { WHOLE_DOCUMENT: true, FORBID_ATTR: ['src'] });
};

module.exports = {
    capture,
    purify,
};
