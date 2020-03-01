import pakunek.*;

public class Main {
    public static void main(String[] args)
    {
        Jamnik j = new Jamnik();

        j.setWiek(10);
        j.setDlugosc(120);
        j.setKolor("purpurowy");

        System.out.println(j.getWiek() + "\n" + j.getKolor() + "\n");
        j.zmierzDlugosc();
    }
}
