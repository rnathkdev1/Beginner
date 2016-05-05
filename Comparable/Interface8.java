import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;

public class Interface8{

    public static void main(String args[]){
        
        System.out.println("Array :: ");
        int[] mant=new int[5];
        mant[0]=5;
        mant[1]=7;
        mant[2]=8;
        mant[3]=3;
        mant[4]=2;
        
        System.out.println(Arrays.toString(mant));
        Arrays.sort(mant);
        System.out.println(Arrays.toString(mant));

    }

}