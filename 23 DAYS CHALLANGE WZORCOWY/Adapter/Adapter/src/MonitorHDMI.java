public class MonitorHDMI implements HDMI_Interface {
    private String obraz;

    public MonitorHDMI() {
        obraz="Wyswietlam obraz monitora!";
    }

    public void wyswietlHDMI() {
        System.out.println(obraz);
    }
}