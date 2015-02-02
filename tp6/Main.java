
public class Main
{
    public static void main(String[] args) {
        Semaphore s = new Semaphore(1);

        /* création des threads */
        ThreadTP6 t1 = new ThreadTP6(s, "t1");
        ThreadTP6 t2 = new ThreadTP6(s, "t2");

        /* on les lance */
        t1.start();
        t2.start();

    }
}