public class IP {
    private int pos;
    private long ipValue;

    public IP(String mask) {
        pos = Integer.parseInt(mask.split("/")[1]);
        ipValue = ipToLong(mask.split("/")[0]);
    }

    private long ipToLong(String ipStr) {
        long ipValue = 0L;
        String[] sub = ipStr.split("\\.");
        ipValue += Long.parseLong(sub[0]) << 24;
        ipValue += Long.parseLong(sub[1]) << 16;
        ipValue += Long.parseLong(sub[2]) << 8;
        ipValue += Long.parseLong(sub[3]);
        return ipValue;
    }

    private boolean contain(String ipStr) {
        long ipValue = ipToLong(ipStr);
        long m = ipValue - this.ipValue;
        if (m >= 0 && m < 1 << (32-pos))
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        IP ip = new IP("192.168.1.0/24");
        System.out.println(ip.contain("192.168.1.255"));
    }
}