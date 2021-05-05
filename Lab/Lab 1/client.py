from tkinter import *
import requests
import json
import datetime


def refresh(event=None):
    try:
        res = requests.get('http://localhost:3000/raw').content.decode("utf8")
        data = json.loads(res)

        current_time = datetime.datetime.now().hour
        description.config(text=str(data["description"]))
        temp.config(text=str((data["temperature"])) + "°C")
    except requests.exceptions.ConnectionError:
        pass


root = Tk()
root.title("Погода")

root.geometry("200x250")


top_frame = Frame(root, bg="#ffb84d", width=100, height=30)
top_frame.pack(side=TOP, fill=X)

middle_frame = Frame(root, bg="#ffffff",  width=100, height=30*3)
middle_frame.pack(expand=True, fill=BOTH)

bottom_frame = Frame(root, bg="#ffb84d", width=100, height=30)
bottom_frame.pack(side=BOTTOM, fill=X)


city = Label(top_frame, font=("Arial Bold", 12), text="Симферополь", bg="#ffb84d")
description = Label(top_frame, font=("Arial", 12), bg="#ffb84d")
temp = Label(middle_frame, font=("Arial Bold", 48), bg="#ffffff")

city.pack(pady=0)
description.pack(pady=0)
temp.pack(expand=True)

refresh()
root.mainloop()

