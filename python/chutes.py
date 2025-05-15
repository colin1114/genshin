import undetected_chromedriver as uc
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import random
import time
import pyperclip
import string
import sys

# 设置控制台输出编码为UTF-8
sys.stdout.reconfigure(encoding='utf-8')

def create_account(username_suffix):
    driver = None
    try:
        print("开始启动浏览器...")
        options = uc.ChromeOptions()
        options.add_argument("--incognito")
        
        driver = uc.Chrome(
            options=options,
            version_main=136
        )

        print("正在打开网页...")
        driver.get("https://chutes.ai/auth/start")
        wait = WebDriverWait(driver, 30)  # 增加等待时间到30秒
        
        print("等待输入框出现...")
        input_box = wait.until(
            EC.presence_of_element_located((By.CSS_SELECTOR, 'input[name="username"]'))
        )
        
        username = f"baipiao{username_suffix}"
        print(f"正在输入用户名: {username}")
        input_box.clear()
        input_box.send_keys(username)

        print("等待提交按钮可点击...")
        submit_button = wait.until(
            EC.element_to_be_clickable((By.CSS_SELECTOR, 'button[type="submit"]'))
        )
        
        print("点击提交按钮...")
        submit_button.click()

        # 增加等待时间，确保页面完全加载
        time.sleep(5)

        print("等待复制按钮出现...")
        # 增加重试机制
        max_retries = 3
        for attempt in range(max_retries):
            try:
                copy_button = wait.until(
                    EC.element_to_be_clickable((By.CSS_SELECTOR, 'button.absolute.inset-0'))
                )
                print("点击复制按钮...")
                copy_button.click()
                break
            except Exception as e:
                if attempt == max_retries - 1:
                    raise e
                print(f"第 {attempt + 1} 次尝试失败，等待后重试...")
                time.sleep(5)
        
        time.sleep(2)
        
        fingerprint = pyperclip.paste()
        print(f"获取到的指纹: {fingerprint}")
        
        # 追加模式打开文件
        with open("password.txt", "a", encoding="utf-8") as f:
            f.write(f"用户名: {username}\n")
            f.write(f"指纹: {fingerprint}\n")
            f.write("-" * 50 + "\n")  # 添加分隔线
        
        print("信息已保存到 password.txt")
        time.sleep(2)

        return True  # 表示成功

    except Exception as e:
        print(f"发生错误: {str(e)}")
        if driver:
            print("保存错误截图...")
            driver.save_screenshot(f"error_{username_suffix}.png")
        return False  # 表示失败
    finally:
        if driver:
            try:
                print("正在关闭浏览器...")
                driver.close()
                driver.quit()
            except Exception as e:
                print(f"关闭浏览器时发生错误: {str(e)}")

def main():
    # 使用字母a到j作为后缀
    suffixes = list(string.ascii_lowercase)[:10]
    successful_accounts = 0
    
    for suffix in suffixes:
        print(f"\n开始创建第 {suffix} 个账号...")
        if create_account(suffix):
            successful_accounts += 1
        else:
            print(f"账号 {suffix} 创建失败，继续下一个...")
        
        time.sleep(5)  # 增加账号之间的等待时间
        print(f"第 {suffix} 个账号处理完成")
        print("-" * 50)
        print(f"当前成功创建账号数: {successful_accounts}/{len(suffixes)}")

if __name__ == "__main__":
    main()