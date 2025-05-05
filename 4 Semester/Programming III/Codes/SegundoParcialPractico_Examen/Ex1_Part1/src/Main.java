import java.util.concurrent.ThreadLocalRandom;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        // Inicializar hilos
        Tortuga t = new Tortuga();
        Liebre l = new Liebre();
        // Correr con start para que corran al mismo tiempo
        t.start();
        l.start();
        // Nuevo hilo para control de los hilos anteriores
        new Thread(new Runnable() {
            @Override
            public void run() {
                while (true){
                    // Esperar para verificar las acciones de tortuga y liebre
                    try {
                        Thread.sleep(100);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    int posT=t.getPos(); // obtener posicion de la tortuga en el tablero
                    int posL=l.getPos(); // obtener posicion de la liebre en el tablero
                    if (posT==70 || posL==70){ // si alguno finalizó la carrera
                        // detener carrera
                        t.interrupt();
                        t.mute();
                        l.interrupt();
                        l.mute();
                        // Mensaje de ganador o empate
                        if (posT==posL) {
                            System.out.println("Empate");
                        } else if (posT==70) {
                            System.out.println("Ganador: Tortuga!!");
                        } else {
                            System.out.println("Ganador: Liebre!!");
                        }
                        break;
                    }
                }
            }
        }).start();
    }
}

// ------------------------------------ Thread Tortuga ------------------------------------
class Tortuga extends Thread implements Runnable{
    int pos = 1; // contador para casillas
    boolean muted = false; // bandera para detener la carrera

    // Acciones a realizar durante la carrera
    public void avanceRapido(){
        pos+=3;
        if (pos>70)
            pos=70;
    }
    public void avanceLento(){
        pos+=1;
        if (pos>70)
            pos=70;
    }
    public void resbalar(){
        pos-=6;
        if (pos<1)
            pos=1;
    }
    // getter
    public int getPos(){
        return pos;
    }
    // manejo de bandera
    public void mute(){
        this.muted=true;
    }
    @Override
    public void run(){
        while (pos<70){
            // Calcular probabilidad
            int probAction = ThreadLocalRandom.current().nextInt(0, 100);

            if (probAction<=50) // 50% avance rapido
                avanceRapido();
            else if (probAction>50 && probAction<=70) { // 20% resbalar
                resbalar();
            } else if (probAction>70 && probAction<=100) { // 30% avance lento
                avanceLento();
            }
            // Mostrar en tablero
            if (!muted) {
                String display = "";
                for (int i = 0; i < this.pos; i++) // Contar espacios
                    display+=" ";
                System.out.println(display + "T");
                if (this.pos==70) // Si termino la carrera
                    this.mute();
            }
            // Esperar 1 segundo
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                break;
            }
        }
    }
}

// ------------------------------------ Thread Liebre  ------------------------------------
class Liebre extends Thread implements Runnable{
    int pos = 1; // contador para casillas
    boolean muted = false; // bandera para detener la carrera
    // Acciones a realizar durante la carrera
    public void granSalto(){
        pos+=9;
        if (pos>70)
            pos=70;
    }
    public void pequeSalto(){
        pos+=1;
        if (pos>70)
            pos=70;
    }
    public void resbalarGrande(){
        pos-=12;
        if (pos<1)
            pos=1;
    }
    public void resbalarPeque(){
        pos-=2;
        if (pos<1)
            pos=1;
    }
    // getter
    public int getPos(){
        return pos;
    }
    // manejo de bandera
    public void mute(){
        this.muted=true;
    }

    @Override
    public void run(){
        while (pos<70){
            // Calcular probabilidad
            int probAction = ThreadLocalRandom.current().nextInt(0, 100);

            if (probAction<=20) // 20% dormir
                continue;
            else if (probAction>20 && probAction<=40) { // 20% gran salto
                granSalto();
            } else if (probAction>40 && probAction<=50) { // 20% resbalo grande
                resbalarGrande();
            } else if (probAction>50 && probAction<=80) { // 30% salto pequeño
                pequeSalto();
            } else if ((probAction>80 && probAction<=100)) { // 20% resbalo pequeño
                resbalarPeque();
            }
            // Mostrar en tablero
            if (!muted) {
                String display = "";
                for (int i = 0; i < this.pos; i++)
                    display+=" ";
                System.out.println(display + "L");
                if (this.pos==70)
                    this.mute();
            }
            // Esperar 1 segundo
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                break;
            }
        }
    }
}
