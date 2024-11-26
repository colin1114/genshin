from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
import time

driver = webdriver.Chrome()

try:
    # 循环访问 note.re/1 到 note.re/200
    for i in range(1, 10000):
        url = f"http://note.ms/{i}"

        # 打开目标 URL
        driver.get(url)

        try:
            # 查找文本区域并填写内容
            textarea = driver.find_element(By.CLASS_NAME, "content")  # 根据实际的 HTML 结构调整定位
            textarea.clear()
            textarea.send_keys("www.luogu.com.cn/team/54817")

       # 提交表单（假设有提交按钮）
            submit_button = driver.find_element(By.NAME, "submit")  # 根据实际按钮的属性替换
            submit_button.click()

            print(f"Successfully submitted 'hello' to {url}.")
        except Exception as e:
            print(f"Failed to submit to {url}. Error: {e}")

        # 等待 2 秒，避免频繁请求触发反爬虫机制
        time.sleep(1)

finally:
    # 关闭浏览器
    driver.quit()
