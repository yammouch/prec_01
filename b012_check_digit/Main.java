import java.util.*;

public class Main {
  public static void main(String[] args) {
    int n, sum, dig;
    Scanner sc = new Scanner(System.in);
    String str = sc.nextLine();
    n = Integer.parseInt(str);
    for (int i = 0; i < n; i++) {
      str = sc.nextLine();
      sum = 0;
      int j = 0; while (true) {
        dig = Integer.parseInt(str.substring(2*j, 2*j+1));
        dig *= 2;
        if (10 <= dig) dig = dig % 10 + 1;
        sum += dig;
        if (7 <= j) break;
        dig = Integer.parseInt(str.substring(2*j+1, 2*j+2));
        sum += dig;
        j++;
      }
      System.out.println((10 - (sum%10))%10);
    }
  }
}
