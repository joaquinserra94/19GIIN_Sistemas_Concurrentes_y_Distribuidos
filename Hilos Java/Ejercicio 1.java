// Esta es la clase del hilo
class NewThread implements Runnable {
    Thread t;
    NewThread() {
    // Crea un nuevo hilo
    t = new Thread(this,"Hilo Hijo");
    System.out.println("Hilo Hijo: " + t);
    t.start();
    }
   // este es el punto de entrada del hilo
    public void run() {
    try {
    for (int i=5;i>0;i--) {
    System.out.println("Hilo hijo: " + i);
    Thread.sleep(500);
    }
    } catch (InterruptedException e){
    System.out.println("Interrupcion del hilo hijo");
    }
    System.out.println("Sale de hilo hijo.");
    }
   }
   //Esta es la clase principal
   class ThreadDemo {
    public static void main(String args[]) {
   NewThread hilo; // crea un nuevo hilo
   hilo = new NewThread(); // crea un nuevo hilo
    try {
    for (int i=5;i>0;i--) {
    System.out.println("Hilo principal: "+i);
    Thread.sleep(1000);
    }
    } catch (InterruptedException e) {
    System.out.println("Interrupcion del hilo principal");
    }
    System.out.println("Sale de hilo principal.");
    }
   }

// Path: Hilos%20Java/Ejercicio%202.java
// Compare this snippet from Hilos%20Java/Ejercicio%1.java:
// // Esta es la clase hilo
// class NewThread implements Runnable {
//     Thread t;
//     NewThread() {
//     // Crea un nuevo hilo
//     t = new Thread(this,"Hilo Hijo");
//     System.out.println("Hilo Hijo: " + t);
//     t.start();
//     }
