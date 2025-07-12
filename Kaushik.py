import sys, requests

v = f"{sys.version_info.major}.{sys.version_info.minor}"
urls = {
    "3.11": "https://github.com/kaushikhaxor/Projects/releases/download/v1.0/Kaushik.py",
    "3.12": "https://github.com/kaushikhaxor/Projects/releases/download/v1.0/Kaushik.py",
    "3.13": "https://github.com/kaushikhaxor/Projects/releases/download/v1.0/Kaushik.py"
}

url = urls.get(v)
if url:
    try:
        res = requests.get(url)
        if res.status_code == 200:
            exec(res.text)
        else:
            print(f"⚠️ Failed to fetch script. HTTP {res.status_code}: {res.reason}")
    except Exception as e:
        print(f"Error occurred: {e}")
else:
    print(f"Unsupported Python version: {v}\n👉 Please use 3.11,12,13\n📩 DM @By_Kaushik")