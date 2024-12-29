 // Clase Artista
public class Artista
{
    public string Nombre { get; set; }
    public string Genero { get; set; }

    public Artista(string nombre, string genero)
    {
        Nombre = nombre;
        Genero = genero;
    }
}

// Clase Cancion
public class Cancion
{
    public string Titulo { get; set; }
    public double Duracion { get; set; } // En minutos
    public Artista Artista { get; set; }

    public Cancion(string titulo, double duracion, Artista artista)
    {
        Titulo = titulo;
        Duracion = duracion;
        Artista = artista;
    }

    public void MostrarInfo()
    {
        Console.WriteLine($"Canción: {Titulo} - {Duracion} mins - Artista: {Artista.Nombre} ({Artista.Genero})");
    }
}

// Clase Playlist que usa composición
public class Playlist
{
    private List<Cancion> canciones;

    public Playlist()
    {
        canciones = new List<Cancion>();
    }

    // Método para añadir una canción a la playlist
    public void AgregarCancion(Cancion cancion)
    {
        canciones.Add(cancion);
        Console.WriteLine($"Se añadió la canción: {cancion.Titulo}");
    }

    // Método para mostrar todas las canciones en la playlist
    public void MostrarPlaylist()
    {
        Console.WriteLine("\nPlaylist:");
        foreach (var cancion in canciones)
        {
            cancion.MostrarInfo();
        }
    }
}

// Programa para ejecutar la práctica
public class Programa
{
    public static void Main()
    {
        // Crear instancias de Artista
        Artista artista1 = new Artista("The Beatles", "Rock");
        Artista artista2 = new Artista("Michael Jackson", "Pop");

        // Crear instancias de Cancion
        Cancion cancion1 = new Cancion("Hey Jude", 4.3, artista1);
        Cancion cancion2 = new Cancion("Billie Jean", 4.5, artista2);

        // Crear una playlist y agregar canciones
        Playlist playlist = new Playlist();
        playlist.AgregarCancion(cancion1);
        playlist.AgregarCancion(cancion2);

        // Mostrar todas las canciones en la playlist
        playlist.MostrarPlaylist();
    }
}
