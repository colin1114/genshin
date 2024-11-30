from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# 启动浏览器
driver = webdriver.Chrome("C:\\Users\\hf01\\Music\\chromedriver.exe")

# 设置隐式等待，等待最多 10 秒
driver.implicitly_wait(1.2)

try:
    # 无限循环，遍历并提交表单
    while True:
        # 循环访问 note.re/1 到 note.re/200
        for i in range(1, 1000):
            url = f"http://note.ms/{i}"

            # 打开目标 URL
            print(f"Opening URL: {url}")
            driver.get(url)

            try:
                # 显式等待，确保页面加载完成
                WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.CLASS_NAME, "content")))

                # 查找文本区域并填写内容
                textarea = driver.find_element(By.CLASS_NAME, "content")  # 根据实际的 HTML 结构调整定位
                textarea.clear()

                # 修改文本内容为新的内容
                new_text = """if you are a MC minecraft player and you have luogu, you can join:
www.luogu.com.cn/team/54817.
如果你需要免费大容量网盘，你可以用：
pan.huang1111.cn"""
                textarea.send_keys(new_text)

                # 提交表单（假设有提交按钮）
                submit_button = driver.find_element(By.NAME, "submit")  # 根据实际按钮的属性替换
                submit_button.click()

                # 等待 2 秒
                time.sleep(1.2)
                print(f"Form submitted successfully to {url}.")
            except Exception as e:
                print(f"Failed to submit form to {url}. Error: {e}")

        print("Finished one round. Starting over again...\n")
        # 等待一段时间后再重新开始
        time.sleep(1.2)

finally:
    # 关闭浏览器
    driver.quit()
