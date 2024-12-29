 // Clase Autor
public class Autor
{
    public string Nombre { get; set; }
    public string Nacionalidad { get; set; }

    public Autor(string nombre, string nacionalidad)
    {
        Nombre = nombre;
        Nacionalidad = nacionalidad;
    }
}

// Clase Contenido
public class Contenido
{
    public int NumeroPaginas { get; set; }
    public string Texto { get; set; }

    public Contenido(int numeroPaginas, string texto)
    {
        NumeroPaginas = numeroPaginas;
        Texto = texto;
    }

    public void LeerPagina(int pagina)
    {
        Console.WriteLine($"Leyendo la página {pagina}...");
    }
}

// Clase Formato
public class Formato
{
    public string Tipo { get; set; } // Por ejemplo: PDF, ePub, etc.
    public double Tamano { get; set; } // Tamaño en MB

    public Formato(string tipo, double tamano)
    {
        Tipo = tipo;
        Tamano = tamano;
    }
}

// Clase LibroDigital que utiliza composición
public class LibroDigital
{
    public Autor Autor { get; set; }
    public Contenido Contenido { get; set; }
    public Formato Formato { get; set; }

    public LibroDigital(Autor autor, Contenido contenido, Formato formato)
    {
        Autor = autor;
        Contenido = contenido;
        Formato = formato;
    }

    public void MostrarInfo()
    {
        Console.WriteLine($"Libro de {Autor.Nombre} ({Autor.Nacionalidad})");
        Console.WriteLine($"Formato: {Formato.Tipo} - Tamaño: {Formato.Tamano} MB");
        Console.WriteLine($"Páginas: {Contenido.NumeroPaginas}");
    }
}

// Ejemplo de uso
public class Programa
{
    public static void Main()
    {
        Autor autor = new Autor("Gabriel García Márquez", "Colombiana");
        Contenido contenido = new Contenido(350, "Texto del libro...");
        Formato formato = new Formato("ePub", 1.5);

        LibroDigital libro = new LibroDigital(autor, contenido, formato);

        libro.MostrarInfo();
        contenido.LeerPagina(5);
    }
}

