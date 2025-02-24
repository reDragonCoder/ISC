# Connect to PokeAPI using Python & HTTP Protocol (Hypertext Transfer Protocol)

# Library for sending HTTP requests
import requests
from urllib.request import urlopen
# Library for handling image data
from PIL import Image, ImageTk
# Library for creating a GUI interface
import tkinter as tk

# API-endpoint
base_url = "https://pokeapi.co/api/v2"

def get_pokemon_info(name):
    url = f"{base_url}/pokemon/{name}"

    # GET (request data from the server)
    response = requests.get(url)
    
    if response.status_code == 200:
        # response.json() retrieves all pokemon info as a dictionary
        pokemon_data = response.json()
        return pokemon_data
    else:
        print(f"Failed to retrieve data {response.status_code}")
        return None  

def show_pokemon_info():
    name = entry.get().lower()
    pokemon_info = get_pokemon_info(name)

    if pokemon_info:
        # Update window title
        root.title(f"{pokemon_info['name'].capitalize()} Info")

        # Display Pokemon info
        name_label.config(text=f"Name: {pokemon_info['name'].capitalize()}")
        id_label.config(text=f"ID: {pokemon_info['id']}") 
        height_label.config(text=f"Height: {pokemon_info['height']} decimetres") 
        weight_label.config(text=f"Weight: {pokemon_info['weight']} hectograms") 

        # Display Pokemon image
        url_image = pokemon_info['sprites']['other']['official-artwork']['front_default']
        if url_image:
            try:
                image = Image.open(urlopen(url_image))
                new_size = (200, 200)
                image = image.resize(new_size)
                photo = ImageTk.PhotoImage(image)
                image_label.config(image=photo)
                image_label.image = photo  # Keeping reference to avoid garbage collection
            except Exception as e:
                print(f"Error loading image: {e}")
                image_label.config(text="Error loading image")
                image_label.image = None
        else:
            print("No image available for this Pokemon.")
            image_label.config(text="No image available")
            image_label.image = None
    else:
        tk.messagebox.showerror("Error", "Pokemon not found.")
        name_label.config(text="")
        id_label.config(text="")
        height_label.config(text="")
        weight_label.config(text="")
        types_label.config(text="")
        image_label.config(image='')
        image_label.image = None

def center_window(win, width, height):
    win.geometry(f"{width}x{height}")
    win.update_idletasks()
    x = (win.winfo_screenwidth() // 2) - (width // 2)
    y = (win.winfo_screenheight() // 2) - (height // 2)
    win.geometry(f"{width}x{height}+{x}+{y}")

def reset_fields():
    entry.delete(0, tk.END)
    name_label.config(text="")
    id_label.config(text="")
    height_label.config(text="")
    weight_label.config(text="")
    types_label.config(text="")
    image_label.config(image='')
    image_label.image = None

# GUI config
root = tk.Tk()
root.title("Pokemon Info")

# Center the window on the screen
center_window(root, 800, 600)

# Entry to input Pokemon name
entry = tk.Entry(root, font=("Arial", 16))
entry.pack(pady=10)

# Buttons
button_frame = tk.Frame(root)
button_frame.pack(pady=5)

button_search = tk.Button(button_frame, text="Search", command=show_pokemon_info, font=("Arial", 16))
button_search.pack(side=tk.LEFT, padx=5)

button_reset = tk.Button(button_frame, text="Reset", command=reset_fields, font=("Arial", 16))
button_reset.pack(side=tk.LEFT, padx=5)

# Labels for displaying Pokemon info
name_label = tk.Label(root, text="", font=("Arial", 16))
name_label.pack(pady=15)

id_label = tk.Label(root, text="", font=("Arial", 16))
id_label.pack(pady=5)

height_label = tk.Label(root, text="", font=("Arial", 16))
height_label.pack(pady=5)

weight_label = tk.Label(root, text="", font=("Arial", 16))
weight_label.pack(pady=5)

types_label = tk.Label(root, text="", font=("Arial", 16))
types_label.pack(pady=5)

# Label for displaying Pokemon image
image_label = tk.Label(root)
image_label.pack(pady=15)

# Tkinter loop
root.mainloop()
