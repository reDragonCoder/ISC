# Connect to NASA API using Python & HTTP Protocol (Hypertext Transfer Protocol)

# Libraries for sending HTTP requests
import requests
from urllib.request import urlopen
# Library for handling image data
from PIL import Image, ImageTk
# Library for creating a GUI interface
import tkinter as tk

# API-endpoint
base_url = "https://api.nasa.gov/planetary/apod"

# API key
api_key = ""

def get_astronomyPic(date):
    url = f"{base_url}?api_key={api_key}&date={date}"

    # GET (request data from the server)
    response = requests.get(url)

    if response.status_code == 200:
        # response.json() retrieves the data as a dictionary
        astronomyPic_data = response.json()
        return astronomyPic_data
    else:
        print(f"Failed to retrieve data {response.status_code}")
        return None

def show_astronomyPic_data():
    yyyy = entryYear.get()
    mm = entryMonth.get()
    dd = entryDay.get()
    date = yyyy + "-" + mm + "-" + dd
    astronomyPic_info = get_astronomyPic(date)

    if astronomyPic_info:
        # Display pic info
        title_label.config(text=f"Title: {astronomyPic_info['title'].capitalize()}")
        date_label.config(text=f"Date: {astronomyPic_info['date']}")

        explanation_textbox.config(state=tk.NORMAL)
        explanation_textbox.delete(1.0, tk.END)
        explanation_textbox.insert(tk.END, f"{astronomyPic_info['explanation']}")
        explanation_textbox.config(state=tk.DISABLED)

        # Display image/picture
        url_image = astronomyPic_info['url']
        if url_image:
            try:
                image = Image.open(urlopen(url_image))
                new_size = (300, 300)
                image = image.resize(new_size)
                photo = ImageTk.PhotoImage(image)
                image_label.config(image=photo)
                image_label.image = photo # Keeping reference to avoid garbage collection
            except Exception as e:
                print("Error loading picture")
                image_label.image = None
        else:
            print("Picture not available for this date")
            image_label.image = None
    else:
        print("Error")
        title_label.config(text="")
        date_label.config(text="")
        explanation_textbox.delete(1.0, tk.END)
        image_label.config(image='')
        image_label.image = None

def center_window(win, width, height):
    win.geometry(f"{width}x{height}")
    win.update_idletasks()
    x = (win.winfo_screenwidth() // 2) - (width // 2)
    y = (win.winfo_screenheight() // 2) - (height // 2)
    win.geometry(f"{width}x{height}+{x}+{y}")

def reset_fields():
    entryYear.delete(0, tk.END)
    entryMonth.delete(0, tk.END)
    entryDay.delete(0, tk.END)
    title_label.config(text="")
    date_label.config(text="")
    explanation_textbox.delete(tk.END, "")
    image_label.config(image='')
    image_label.image = None

# GUI config
root = tk.Tk()
root.title("NASA - Astronomy Picture Of The Day")

# Center the window on the screen
center_window(root, 900, 700)

# Entries to input date
labelEntries_frame = tk.Frame(root)
labelEntries_frame.pack(pady=5)

labelYear = tk.Label(labelEntries_frame, text="Year (YYYY format)", font=("Arial", 12))
labelYear.pack(side=tk.LEFT, padx=10)

labelMonth = tk.Label(labelEntries_frame, text="Month (MM format)", font=("Arial", 12))
labelMonth.pack(side=tk.LEFT, padx=30)

labelDay = tk.Label(labelEntries_frame, text="Day (DD format)", font=("Arial", 12))
labelDay.pack(side=tk.LEFT, padx=10)

entry_frame = tk.Frame(root)
entry_frame.pack(pady=5)

entryYear = tk.Entry(entry_frame, font=("Arial", 12))
entryYear.pack(side=tk.LEFT, padx=5)

entryMonth = tk.Entry(entry_frame, font=("Arial", 12))
entryMonth.pack(side=tk.LEFT, padx=5)

entryDay = tk.Entry(entry_frame, font=("Arial", 12))
entryDay.pack(side=tk.LEFT, padx=5)

# Buttons
button_frame = tk.Frame(root)
button_frame.pack(pady=5)

button_search = tk.Button(button_frame, text="Search", command=show_astronomyPic_data, font=("Arial", 12))
button_search.pack(side=tk.LEFT, padx=5)

button_reset = tk.Button(button_frame, text="Reset", command=reset_fields, font=("Arial", 12))
button_reset.pack(side=tk.LEFT, padx=5)

# Labels for displaying picture info
title_label = tk.Label(root, text="", font=("Arial", 12))
title_label.pack(pady=5)

date_label = tk.Label(root, text="", font=("Arial", 12))
date_label.pack(pady=5)

explanation_textbox = tk.Text(root, wrap=tk.WORD, font=("Arial", 12), height=10, width=70)
explanation_textbox.pack(pady=5)
explanation_textbox.config(state=tk.DISABLED)

# Label for displaying the picture
image_label = tk.Label(root)
image_label.pack(pady=5)

# Tkinter loop
root.mainloop()

