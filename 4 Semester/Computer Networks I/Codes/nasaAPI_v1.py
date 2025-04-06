# Connect to NASA API using Python & HTTP Protocol (Hypertext Transfer Protocol)

# Library for sending HTTP requests
import requests

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

data = get_astronomyPic("1995-06-16")
print(data)
