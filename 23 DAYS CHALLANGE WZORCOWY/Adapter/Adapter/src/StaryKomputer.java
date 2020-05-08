public class StaryKomputer {
    VGA_Interface monitor = null;
    public StaryKomputer(VGA_Interface w) {
        monitor = w;
    }
    public void grajWGre() {
        monitor.wyswietlVGA();
    }
}

