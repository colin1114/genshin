import asyncio
from playwright.async_api import async_playwright

async def submit_form():
    async with async_playwright() as p:
        browser = await p.chromium.launch(headless=True)  # 启动无头浏览器
        page = await browser.new_page()

        # 循环访问 note.ms/1 到 note.ms/200
        for i in range(1, 201):
            url = f'http://note.ms/{i}'
            await page.goto(url)

            # 填写表单内容
            await page.fill('.content', 'hello')

            # 提交表单
            await page.click('button[name="submit"]')

            print(f"Successfully submitted 'hello' to {url}.")
            await asyncio.sleep(1)  # 保持页面打开1秒

        await browser.close()

# 运行
asyncio.run(submit_form())
