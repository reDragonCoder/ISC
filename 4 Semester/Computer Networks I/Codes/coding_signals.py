# Author: reDragonCoder

# ------------ LIBRARIES ------------
import tkinter as tk
import tkinter.font as tkFont
import tkinter.messagebox as msgbox
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg 

# ------------ CONSTANTS ------------
canvas = None

# ---------- GUI FUNCTIONS ----------
def center_window(win, width, height):
    win.geometry(f"{width}x{height}")
    win.update_idletasks()
    x=(win.winfo_screenwidth()//2)-(width//2)
    y=(win.winfo_screenheight()//2)-(height//2)
    win.geometry(f"{width}x{height}+{x}+{y-40}")

def show_frame(frame):
    global canvas  
    for f in (frame0, frame1, frame2, frame3, frame4, frame5, frame6):
        f.pack_forget()
    frame.pack(expand=True, fill="both")

    if frame == frame0:
        entrysequence1.delete(0, tk.END)
        entrysequence2.delete(0, tk.END)
        if canvas is not None:
            canvas.get_tk_widget().destroy()
        canvas = None

# ---------- GRAPHIC FUNCTIONS ----------
def nrz_l():
    global canvas

    if canvas is not None:
        canvas.get_tk_widget().destroy()
    
    sequence=entrysequence1.get().strip()

    if any(bit not in "01" for bit in sequence) or len(sequence) == 0:
        import tkinter.messagebox as messagebox
        messagebox.showerror("Error", "La secuencia debe contener solo los dígitos 0 y 1")
        entrysequence1.delete(0, tk.END)
        return
    
    # Initialize lists for x and y coordinates and a time variable t
    x=[]
    y=[]
    t=0

    # Level is 1 when the bit is "1", and 0 when the bit is "0"
    # NOTE: Two points are added for each bit to simulate a step in the plot
    for bit in sequence:
        x.append(t)
        level=1 if bit=="1" else 0
        y.append(level)
        t+=1
        x.append(t)
        y.append(level)

    fig=plt.Figure(figsize=(6, 4), dpi=100)
    ax=fig.add_subplot(111)
    ax.plot(x, y, color='blue')
    ax.set_title("NRZ-L")
    ax.set_yticks([0,1])
    ax.set_ylim(-0.5, 1.5)

    tick_positions=[i+0.5 for i in range(len(sequence))]
    ax.set_xticks(tick_positions)
    ax.set_xticklabels(list(sequence), fontsize=10)

    canvas=FigureCanvasTkAgg(fig, master=frame1)  
    canvas.draw()
    canvas.get_tk_widget().pack(side="top", fill="both", expand=True)

    entrysequence1.delete(0, tk.END)

def nrz_i():
    global canvas

    if canvas is not None:
        canvas.get_tk_widget().destroy()
    
    sequence=entrysequence2.get().strip()

    if any(bit not in "01" for bit in sequence) or len(sequence) == 0:
        import tkinter.messagebox as messagebox
        messagebox.showerror("Error", "La secuencia debe contener solo los dígitos 0 y 1")
        entrysequence2.delete(0, tk.END)
        return
    
    # Initialize lists for x and y coordinates, time variable t, and a list 
    # (bit_levels) to store the signal level for each bit
    x=[]
    y=[]
    t=0
    bit_levels=[]

    # Set the initial level for NRZ-I (starting at 0)
    current_level=0

    # if the bit is "1" the signal level toggles, and if the bit is "0" the level remains the same
    for bit in sequence:
        if bit=="1":
            current_level=1-current_level
        bit_levels.append(current_level)
        x.append(t)
        y.append(current_level)
        t+=1
        x.append(t)
        y.append(current_level)
    
    # Decode the signal by comparing adjacent levels:
    # If there is a transition (the level changes), that decodes as "1"
    # If there is no transition, it decodes as "0"
    decoded=""
    for i in range(1, len(bit_levels)):
        if bit_levels[i] != bit_levels[i-1]:
            decoded+="1"
        else:
            decoded+="0"

    fig=plt.Figure(figsize=(6, 4), dpi=100)
    ax=fig.add_subplot(111)
    ax.plot(x, y, color='blue')
    ax.set_title("NRZ-L")
    ax.set_yticks([0,1])
    ax.set_ylim(-0.5, 1.5)
    tick_positions=[i+0.5 for i in range(len(sequence))]
    ax.set_xticks(tick_positions)
    ax.set_xticklabels(list(sequence), fontsize=10)
    canvas=FigureCanvasTkAgg(fig, master=frame2)  
    canvas.draw()
    canvas.get_tk_widget().pack(side="top", fill="both", expand=True)
    entrysequence2.delete(0, tk.END)

def bipolar_ami():
    global canvas

    if canvas is not None:
        canvas.get_tk_widget().destroy()
    
    sequence=entrysequence3.get().strip()

    if any(bit not in "01" for bit in sequence) or len(sequence) == 0:
        import tkinter.messagebox as messagebox
        messagebox.showerror("Error", "La secuencia debe contener solo los dígitos 0 y 1")
        entrysequence3.delete(0, tk.END)
        return
    
    # Initialize lists for x and y coordinates, time variable t, and a list 
    # (bit_levels) to store the signal level for each bit
    x=[]
    y=[]
    t=0

    # The temp variable alters the polarity based on the previous "1" bit in the sequence
    temp=True
    for i in range(len(sequence)):
        x.append(t)
        if sequence[i]=="1" and temp:
            data=1
            temp=False
        elif sequence[i]=="1" and not temp:
            data=-1
            temp=True
        else:
            data=0
        y.append(data)
        t+=1
        x.append(t)
        y.append(data)

    fig=plt.Figure(figsize=(6, 4), dpi=100)
    ax=fig.add_subplot(111)
    ax.plot(x, y, color='blue')
    ax.set_title("Bipolar AMI")
    ax.set_yticks([-1,0,1])
    ax.set_ylim(-1.5, 1.5)
    tick_positions=[i+0.5 for i in range(len(sequence))]
    ax.set_xticks(tick_positions)
    ax.set_xticklabels(list(sequence), fontsize=10)
    canvas=FigureCanvasTkAgg(fig, master=frame3)  
    canvas.draw()
    canvas.get_tk_widget().pack(side="top", fill="both", expand=True)
    entrysequence3.delete(0, tk.END)

def pseudoternary():
    global canvas

    if canvas is not None:
        canvas.get_tk_widget().destroy()
    
    sequence=entrysequence4.get().strip()

    if any(bit not in "01" for bit in sequence) or len(sequence) == 0:
        import tkinter.messagebox as messagebox
        messagebox.showerror("Error", "La secuencia debe contener solo los dígitos 0 y 1")
        entrysequence4.delete(0, tk.END)
        return
    
    # Initialize lists for x and y coordinates, time variable t, and a list 
    # (bit_levels) to store the signal level for each bit
    x=[]
    y=[]
    t=0

    # The temp variable alters the polarity based on the previous "0" bit in the sequence
    temp=True
    for i in range(len(sequence)):
        x.append(t)
        if sequence[i]=="0" and temp:
            data=1
            temp=False
        elif sequence[i]=="0" and not temp:
            data=-1
            temp=True
        else:
            data=0
        y.append(data)
        t+=1
        x.append(t)
        y.append(data)

    fig=plt.Figure(figsize=(6, 4), dpi=100)
    ax=fig.add_subplot(111)
    ax.plot(x, y, color='blue')
    ax.set_title("Bipolar AMI")
    ax.set_yticks([-1,0,1])
    ax.set_ylim(-1.5, 1.5)
    tick_positions=[i+0.5 for i in range(len(sequence))]
    ax.set_xticks(tick_positions)
    ax.set_xticklabels(list(sequence), fontsize=10)
    canvas=FigureCanvasTkAgg(fig, master=frame4)  
    canvas.draw()
    canvas.get_tk_widget().pack(side="top", fill="both", expand=True)
    entrysequence4.delete(0, tk.END)

def manchester():
    global canvas

    if canvas is not None:
        canvas.get_tk_widget().destroy()
    
    sequence=entrysequence5.get().strip()

    if any(bit not in "01" for bit in sequence) or len(sequence) == 0:
        import tkinter.messagebox as messagebox
        messagebox.showerror("Error", "La secuencia debe contener solo los dígitos 0 y 1")
        entrysequence5.delete(0, tk.END)
        return
    
    # Initialize lists for x and y coordinates, time variable t, and a list 
    # (bit_levels) to store the signal level for each bit
    x=[]
    y=[]
    t=0

    # Construct the Manchester encoded signal using the IEEE 802.3 convention:
    # Bit '0': first half at 1, second half at 0
    # Bit '1': first half at 0, second half at 1
    for bit in sequence:
        if bit=="0":
            first_half=1
            second_half=0
        else:
            first_half=0
            second_half=1
        
        x.append(t)
        y.append(first_half)
        x.append(t+0.5)
        y.append(first_half)
        x.append(t+0.5)
        y.append(second_half)
        x.append(t+1)
        y.append(second_half)
        t+=1

    fig=plt.Figure(figsize=(6, 4), dpi=100)
    ax=fig.add_subplot(111)
    ax.plot(x, y, color='blue')
    ax.set_title("Manchester")
    ax.set_yticks([0,1])
    ax.set_ylim(-0.5, 1.5)
    tick_positions=[i+0.5 for i in range(len(sequence))]
    ax.set_xticks(tick_positions)
    ax.set_xticklabels(list(sequence), fontsize=10)
    canvas=FigureCanvasTkAgg(fig, master=frame5)  
    canvas.draw()
    canvas.get_tk_widget().pack(side="top", fill="both", expand=True)
    entrysequence5.delete(0, tk.END)

def differential_code():
    global canvas

    if canvas is not None:
        canvas.get_tk_widget().destroy()
    
    sequence=entrysequence6.get().strip()

    if any(bit not in "01" for bit in sequence) or len(sequence) == 0:
        import tkinter.messagebox as messagebox
        messagebox.showerror("Error", "La secuencia debe contener solo los dígitos 0 y 1")
        entrysequence6.delete(0, tk.END)
        return
    
    # Initialize lists for x and y coordinates, time variable t, and a list 
    # (bit_levels) to store the signal level for each bit
    x=[]
    y=[]
    t=0

    # Construct the Differential Manchester encoded signal:
    # For bit '0': toggle the signal level at the beginning of the bit period
    # For bit '1': no transition occurs at the beginning
    # In both cases, a mid-bit transition always occurs 
    current_level=1
    for bit in sequence:
        if bit=="0":
            current_level=1-current_level
        
        x.append(t)
        y.append(current_level)
        x.append(t+0.5)
        y.append(current_level)

        current_level=1-current_level
        x.append(t+0.5)
        y.append(current_level)

        x.append(t+1)
        y.append(current_level)
        t+=1

    fig=plt.Figure(figsize=(6, 4), dpi=100)
    ax=fig.add_subplot(111)
    ax.plot(x, y, color='blue')
    ax.set_title("Manchester")
    ax.set_yticks([0,1])
    ax.set_ylim(-0.5, 1.5)
    tick_positions=[i+0.5 for i in range(len(sequence))]
    ax.set_xticks(tick_positions)
    ax.set_xticklabels(list(sequence), fontsize=10)
    canvas=FigureCanvasTkAgg(fig, master=frame6)  
    canvas.draw()
    canvas.get_tk_widget().pack(side="top", fill="both", expand=True)
    entrysequence6.delete(0, tk.END)

# ----------- GUI CONFIG ------------
root=tk.Tk()
root.title("Codificación de señales")

title_font=tkFont.Font(family="Courier", size=40, weight=tkFont.BOLD)
normal_font=tkFont.Font(family="Courier", size=12, weight=tkFont.NORMAL)
button_font=tkFont.Font(family="Courier", size=10, weight=tkFont.BOLD)
frames_font=tkFont.Font(family="Courier", size=15, weight=tkFont.NORMAL)

center_window(root, 900, 700)

container=tk.Frame(root)
container.pack(fill="both", expand=True)

# ----------------- Frames -----------------
frame0=tk.Frame(container, bg="black")
frame1=tk.Frame(container, bg="black")
frame2=tk.Frame(container, bg="black")
frame3=tk.Frame(container, bg="black")
frame4=tk.Frame(container, bg="black")
frame5=tk.Frame(container, bg="black")
frame6=tk.Frame(container, bg="black")

# ----------------- Content -----------------
# Menu content
title0_label=tk.Label(frame0, text="CODIFICACIÓN", font=title_font, bg="black", fg="green")
title0_label.pack(pady=(25, 20), anchor="n")

menu_frame=tk.Frame(frame0, bg="black")
menu_frame.pack()

def add_menu_option(frame, text, option_text, target_frame):
    label=tk.Label(frame, text=text, font=normal_font, bg="black", fg="white")
    label.pack(pady=10)
    button=tk.Button(frame, text=option_text, font=button_font, bg="green", fg="black", command=lambda: show_frame(target_frame), width=20)
    button.pack(pady=(5, 10))

add_menu_option(menu_frame, "1.- No retorno a cero - Nivel (NRZ-L)", "Opción 1", frame1)
add_menu_option(menu_frame, "2.- No retorno a cero - Invertido (NRZ-I)", "Opción 2", frame2)
add_menu_option(menu_frame, "3.- Bipolar AMI (Alternate Mark Inversion)", "Opción 3", frame3)
add_menu_option(menu_frame, "4.- Pseudoternario", "Opción 4", frame4)
add_menu_option(menu_frame, "5.- Manchester", "Opción 5", frame5)
add_menu_option(menu_frame, "6.- Código diferencial", "Opción 6", frame6)


# Frame1 content -> No retorno a cero - Nivel (NRZ-N) 
labelsequence1=tk.Label(frame1, text=" Ingrese la secuencia de datos de manera consecutiva (0's y 1's) ", font=frames_font, bg="black", fg="white")
labelsequence1.pack(pady=30)
entrysequence1=tk.Entry(frame1, font=frames_font)
entrysequence1.pack(pady=5)
buttonSubmmit1=tk.Button(frame1, text="OK", font=button_font, bg="green", fg="black", command=lambda: nrz_l(), width=20)
buttonSubmmit1.pack(pady=5)
buttonBack1_Frame=tk.Frame(frame1, bg="black")
buttonBack1_Frame.pack(side="bottom", fill="x", padx=10, pady=10)
buttonBack=tk.Button(buttonBack1_Frame, text="Back", font=button_font, bg="green", fg="black", command=lambda: show_frame(frame0), width=20)
buttonBack.pack(side="right")

# Frame2 content -> No retorno a cero - Invertido (NRZ-N) 
labelsequence2=tk.Label(frame2, text=" Ingrese la secuencia de datos de manera consecutiva (0's y 1's) ", font=frames_font, bg="black", fg="white")
labelsequence2.pack(pady=30)
entrysequence2=tk.Entry(frame2, font=frames_font)
entrysequence2.pack(pady=5)
buttonSubmmit2=tk.Button(frame2, text="OK", font=button_font, bg="green", fg="black", command=lambda: nrz_i(), width=20)
buttonSubmmit2.pack(pady=5)
buttonBack2_Frame=tk.Frame(frame2, bg="black")
buttonBack2_Frame.pack(side="bottom", fill="x", padx=10, pady=10)
buttonBack=tk.Button(buttonBack2_Frame, text="Back", font=button_font, bg="green", fg="black", command=lambda: show_frame(frame0), width=20)
buttonBack.pack(side="right")

# Frame3 content -> Bipolar AMI
labelsequence3=tk.Label(frame3, text=" Ingrese la secuencia de datos de manera consecutiva (0's y 1's) ", font=frames_font, bg="black", fg="white")
labelsequence3.pack(pady=30)
entrysequence3=tk.Entry(frame3, font=frames_font)
entrysequence3.pack(pady=5)
buttonSubmmit3=tk.Button(frame3, text="OK", font=button_font, bg="green", fg="black", command=lambda: bipolar_ami(), width=20)
buttonSubmmit3.pack(pady=5)
buttonBack3_Frame=tk.Frame(frame3, bg="black")
buttonBack3_Frame.pack(side="bottom", fill="x", padx=10, pady=10)
buttonBack=tk.Button(buttonBack3_Frame, text="Back", font=button_font, bg="green", fg="black", command=lambda: show_frame(frame0), width=20)
buttonBack.pack(side="right")

# Frame4 content -> Pseudoternario
labelsequence4=tk.Label(frame4, text=" Ingrese la secuencia de datos de manera consecutiva (0's y 1's) ", font=frames_font, bg="black", fg="white")
labelsequence4.pack(pady=30)
entrysequence4=tk.Entry(frame4, font=frames_font)
entrysequence4.pack(pady=5)
buttonSubmmit4=tk.Button(frame4, text="OK", font=button_font, bg="green", fg="black", command=lambda: pseudoternary(), width=20)
buttonSubmmit4.pack(pady=5)
buttonBack4_Frame=tk.Frame(frame4, bg="black")
buttonBack4_Frame.pack(side="bottom", fill="x", padx=10, pady=10)
buttonBack=tk.Button(buttonBack4_Frame, text="Back", font=button_font, bg="green", fg="black", command=lambda: show_frame(frame0), width=20)
buttonBack.pack(side="right")

# Frame5 content -> Manchester
labelsequence5=tk.Label(frame5, text=" Ingrese la secuencia de datos de manera consecutiva (0's y 1's) ", font=frames_font, bg="black", fg="white")
labelsequence5.pack(pady=30)
entrysequence5=tk.Entry(frame5, font=frames_font)
entrysequence5.pack(pady=5)
buttonSubmmit5=tk.Button(frame5, text="OK", font=button_font, bg="green", fg="black", command=lambda: manchester(), width=20)
buttonSubmmit5.pack(pady=5)
buttonBack5_Frame=tk.Frame(frame5, bg="black")
buttonBack5_Frame.pack(side="bottom", fill="x", padx=10, pady=10)
buttonBack=tk.Button(buttonBack5_Frame, text="Back", font=button_font, bg="green", fg="black", command=lambda: show_frame(frame0), width=20)
buttonBack.pack(side="right")

# Frame6 content -> Manchester
labelsequence6=tk.Label(frame6, text=" Ingrese la secuencia de datos de manera consecutiva (0's y 1's) ", font=frames_font, bg="black", fg="white")
labelsequence6.pack(pady=30)
entrysequence6=tk.Entry(frame6, font=frames_font)
entrysequence6.pack(pady=5)
buttonSubmmit6=tk.Button(frame6, text="OK", font=button_font, bg="green", fg="black", command=lambda: differential_code(), width=20)
buttonSubmmit6.pack(pady=5)
buttonBack6_Frame=tk.Frame(frame6, bg="black")
buttonBack6_Frame.pack(side="bottom", fill="x", padx=10, pady=10)
buttonBack=tk.Button(buttonBack6_Frame, text="Back", font=button_font, bg="green", fg="black", command=lambda: show_frame(frame0), width=20)
buttonBack.pack(side="right")

show_frame(frame0)
root.mainloop()
