public class Adapter implements VGA_Interface, HDMI_Interface {
    HDMI kabel = new HDMI();

    @Override
    public void wyswietlHDMI() {
        kabel.wyswietlHDMI();
    }

    @Override
    public void wyswietlVGA() {
        kabel.wyswietlHDMI();
    }
}