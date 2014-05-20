import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: zhangyang
 * Date: 12/14/13
 */

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int ts = in.nextInt();
        String b = in.nextLine();
        for (int i = 0; i < ts; i++) {
            String ipadd = in.nextLine();
            String iplist[] = ipadd.split(" ");
            if(iplist[0].matches("([0-9]{1,2}|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.([0-9]{1,2}|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.([0-9]{1,2}|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.([0-9]{1,2}|1[0-9][0-9]|2[0-4][0-9]|25[0-5])") == true){
                System.out.println("IPv4");
            } else if (iplist[0].matches("([0-9a-f]+)\\:([0-9a-f]+)\\:([0-9a-f]+)\\:([0-9a-f]+)\\:([0-9a-f]+)\\:([0-9a-f]+)\\:([0-9a-f]+)\\:([0-9a-f]+)") == true){
                System.out.println("IPv6");
            } else {
                System.out.println("Neither");
            }
        }
    }
}
