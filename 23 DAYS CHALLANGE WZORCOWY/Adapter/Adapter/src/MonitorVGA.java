public class MonitorVGA implements VGA_Interface {
    private String obraz;

    public MonitorVGA() {
        obraz="Wyswietlam obraz monitor!";
    }

    public void wyswietlVGA() {
        System.out.println(obraz);
    }
}