public class Main {
    public static void main(String[] args) {
        VGA_Interface vga = new MonitorVGA();
        HDMI_Interface hdmi = new MonitorHDMI();

        StaryKomputer komputer = new StaryKomputer(vga);
        komputer.grajWGre();

        Adapter adapter = new Adapter(hdmi);

        adapter.wyswietlVGA();
        adapter.wyswietlHDMI();
   }
}


