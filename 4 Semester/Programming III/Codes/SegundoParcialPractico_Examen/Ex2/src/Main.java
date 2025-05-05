import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("----- Sistema de gestión de torneos de fútbol ------");

        Comparator<Equipo> comparadorEquipos = (Equipo e1, Equipo e2) -> {
            // Más puntos ganados
            int cmp = Integer.compare(e2.getPuntos(), e1.getPuntos());
            if (cmp != 0) return cmp;

            // Más juegos ganados
            cmp = Integer.compare(e2.getJuegosGanados(), e1.getJuegosGanados());
            if (cmp != 0) return cmp;

            // Mayor diferencia de goles
            cmp = Integer.compare(e2.getDiferencia_de_goles(), e1.getDiferencia_de_goles());
            if (cmp != 0) return cmp;

            // Más goles marcados
            cmp = Integer.compare(e2.getGolesAFavor(), e1.getGolesAFavor());
            if (cmp != 0) return cmp;

            // Menos juegos jugados
            cmp = Integer.compare(e2.getJuegosJugados(), e1.getJuegosJugados());
            if (cmp != 0) return cmp;

            // Orden lexicográfico
            return e1.getNombre().compareTo(e2.getNombre());
        };

        System.out.print("Ingrese el número de torneos que desea procesar: ");
        int numTorneos = Integer.parseInt(sc.nextLine());

        for (int i=0; i<numTorneos; i++) {
            System.out.println("\n==================================================================");
            System.out.println("TORNEO #" + (i + 1));
            System.out.print("Nombre del torneo: ");
            String nombreTorneo = sc.nextLine();

            System.out.print("Ingrese el número de equipos en \"" + nombreTorneo + "\": ");
            int numEquipos = Integer.parseInt(sc.nextLine());

            Map<String, Equipo> equipos = new HashMap<>();

            System.out.println("\nIngrese los nombres de los equipos:");
            for (int j=0; j<numEquipos; j++) {
                System.out.print("Equipo " + (j + 1) + ": ");
                String nombreEquipo = sc.nextLine();
                equipos.put(nombreEquipo, new Equipo(nombreEquipo)); //se guarda en el mapa
            }

            System.out.print("\nIngrese el número de partidos jugados: ");
            int numJuegos = Integer.parseInt(sc.nextLine());

            System.out.println("\nIngrese los resultados de los partidos (formato: nombre1#goles1@goles2#nombre2):");
            for (int k=0; k<numJuegos; k++) {
                System.out.print("Partido " + (k + 1) + ": ");
                String linea = sc.nextLine();
                Leer_Equipos(linea, equipos);
            }

            List<Equipo> listaEquipos = new ArrayList<>(equipos.values());
            listaEquipos.sort(comparadorEquipos);
            System.out.println("\n----------------------------------------------------------------------");
            System.out.println("\nEstadísticas de clasificación del torneo \"" + nombreTorneo + "\".\n");
            System.out.println("\n" + nombreTorneo + "\n");
            int posicion = 1;
            for (Equipo equipo : listaEquipos) {
                // [a]) Team Name [b]p, [c]g ([d]-[e]-[f]), [g]gd ([h]-[i])
                System.out.println(
                        posicion + ") " + equipo.getNombre() + " " +
                                equipo.getPuntos() + "p, " +
                                equipo.getJuegosJugados() + "g (" +
                                equipo.getJuegosGanados() + "-" +
                                equipo.getJuegosEmpatados() + "-" +
                                equipo.getJuegos_perdidos() + "), " +
                                equipo.getDiferencia_de_goles() + "gd (" +
                                equipo.getGolesAFavor() + "-" +
                                equipo.getGolesEnContra() + ")"
                );
                posicion++;
            }

        }
    }

    private static void Leer_Equipos(String linea, Map<String, Equipo> equipos) {
        try {
            String[] partes = linea.split("[#@]");

            String nombre1 = partes[0];
            int goles1 = Integer.parseInt(partes[1]);
            int goles2 = Integer.parseInt(partes[2]);
            String nombre2 = partes[3];

            Equipo equipo1 = equipos.get(nombre1);
            Equipo equipo2 = equipos.get(nombre2);

            if (equipo1 == null || equipo2 == null) {
                System.out.println("Verifique los nombres. \n");
                return;
            }

            equipo1.ActualizarEstadisticas(goles1, goles2);
            equipo2.ActualizarEstadisticas(goles2, goles1);

        } catch (Exception e) {
            System.out.println(" Error al procesar el partido. \n");
        }
    }
}


class Equipo {
    // Atributos ------------------------------------------------------------------------------------------------------
    private final String nombre;
    private int puntos;
    private int juegos_jugados;
    private int juegos_ganados;
    private int juegos_empatados;
    private int juegos_perdidos;
    private int goles_a_favor;
    private int goles_en_contra;

    // Constructor ----------------------------------------------------------------------------------------------------

    public Equipo(String nombre) { this.nombre = nombre; }

    // Actualizar Estadísticas ----------------------------------------------------------------------------------------

    public void ActualizarEstadisticas(int goles_anotados, int goles_recibidos) {
        juegos_jugados ++;
        goles_a_favor += goles_anotados;
        goles_en_contra += goles_recibidos;

        if (goles_anotados > goles_recibidos) {
            juegos_ganados ++;
            puntos += 3;
        } else if (goles_anotados == goles_recibidos) {
            juegos_empatados ++;
            puntos += 1;
        } else {
            juegos_perdidos ++;
        }
    }

    // Métodos GET ----------------------------------------------------------------------------------------------------

    public String getNombre() { return nombre; }
    public int getPuntos() { return puntos; }
    public int getJuegosJugados() { return juegos_jugados; }
    public int getJuegosGanados() { return juegos_ganados; }
    public int getJuegosEmpatados() { return juegos_empatados; }
    public int getJuegos_perdidos() { return juegos_perdidos; }
    public int getGolesAFavor() { return goles_a_favor; }
    public int getGolesEnContra() { return goles_en_contra; }

    public int getDiferencia_de_goles() {
        return goles_a_favor - goles_en_contra;
    }

}
