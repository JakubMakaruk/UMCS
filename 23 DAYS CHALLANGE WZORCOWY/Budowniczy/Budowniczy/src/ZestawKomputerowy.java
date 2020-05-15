public class ZestawKomputerowy {
    private String cpu;
    private String gpu;
    private String ram;
    private String dysk;

    public void setCpu(String cpu) {
        this.cpu = cpu;
    }

    public void setGpu(String gpu) {
        this.gpu = gpu;
    }

    public void setRam(String ram) {
        this.ram = ram;
    }

    public void setDysk(String dysk) {
        this.dysk = dysk;
    }

    public void wyswietl() {
        System.out.println("PROCESOR: " + cpu);
        System.out.println("GRAFIKA: " + gpu);
        System.out.println("RAM: " + ram);
        System.out.println("DYSK: " + dysk);
    }

}