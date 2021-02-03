/*Author: Mandeep Punia*/
//Link:https://www.hackerrank.com/challenges/missing-numbers/problem
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int c1[] = new int[10000];
        int c2[] = new int[10000];
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
            c1[a[i]-1]++;
        }
        int m = sc.nextInt();
        int b[] = new int[m];
        for(int i=0;i<m;i++){
            b[i] = sc.nextInt();
            c2[b[i]-1]++;
        }
        for(int i=0;i<10000;i++){
            if(c1[i]!=c2[i])
                System.out.print((i+1) + " ");
        }
    }
}
