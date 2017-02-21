import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static int getCommand(String s) {
        if (s.equals("Insert")){
            return 0;
        } else if (s.equals("Delete")){
            return 1;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int numElement =  sc.nextInt();
        LinkedList list = new LinkedList();
        for (int i = 0; i < numElement; i ++) {
            int input =  sc.nextInt();
            list.add(input);
        }
        int numQuery =  sc.nextInt();
        for (int i = 0; i < numQuery; i ++) {
            String command =  sc.next();
            switch (getCommand(command)) {
                case 0:
                    {
                        int pos = sc.nextInt();
                        int val = sc.nextInt();
                        try {
                            list.add(pos, val);
                        }
                        catch (Exception e) {
                            
                        }
                    }
                    break;
                case 1:
                    {
                        int pos = sc.nextInt();
                        try {
                            list.remove(list.get(pos));
                        }
                        catch (Exception e) {
                            
                        }
                    }
                    break;
                default:
                    break;
                    
            }
        }
        Object[] l = list.toArray();
        for (int i = 0; i < l.length; i ++){
            System.out.print("" + l[i] + " ");
        }
    }
}
