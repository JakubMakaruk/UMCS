public class Adapter implements VGA_Interface, HDMI_Interface {
    HDMI_Interface hdmi=null;

    public Adapter(HDMI_Interface w) {
        hdmi = w;
    }

    @Override
    public void wyswietlHDMI() {
        hdmi.wyswietlHDMI();
    }

    @Override
    public void wyswietlVGA() {
        hdmi.wyswietlHDMI();
    }
}