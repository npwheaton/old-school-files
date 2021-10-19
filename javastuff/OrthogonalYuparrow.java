import java.util.ArrayList;
import java.util.Scanner;


public class OrthogonalYuparrow {

public static double factor4vector(double array1[], double array2[], int size) {
    double yu1 = 0;
    double u1u1 = 0;
    for (int i = 0; i < size; i++) {
        yu1 += (array1[i] * array2[i]);
    }

    for (int i = 0; i < size; i++) {
        u1u1 += (array2[i] * array2[i]);
    }

    return yu1 / u1u1;

}
public static double RoundtoTheNearest(double target, double decimalPlace){
    double factor = 1/decimalPlace;
    double temptarget = target* factor;
    temptarget = Math.round(temptarget);
    temptarget/=factor;
    return temptarget;
}

public static void main(String[] args) {
    Scanner answer = new Scanner(System.in);
    System.out.println("Input the number of vectors excluding Y");
    int vectnum = answer.nextInt();
    System.out.println("Input vector size");
    int size = answer.nextInt();
    ArrayList<double[]> uvectors = new ArrayList<double[]>();
    ArrayList<double[]> utimesfactor = new ArrayList<double[]>();

    double y[] = new double[size];
    double yup[] = new double[size];
    double yminusyup[] = new double[size];
    double z =0;
    //fill u vectors
    for (int i = 0; i<vectnum; i++){
        double temp[] = new double[size];
        System.out.println("input U"+ (uvectors.size()+ 1));
        for (int j = 0; j<size; j++){
            temp[j] = answer.nextDouble();
        }
        uvectors.add(temp);
    }

    //fill y
    System.out.println("Input Y");
    for (int i = 0; i < size; i++) {
        y[i] = answer.nextDouble();
    }
    answer.close();

    for (int i = 0; i<vectnum; i++){
        double[] afterFactortimesU = new double[size];
        double[] getorigU = uvectors.get(i);
        double factor = factor4vector(y, getorigU, size);
        for (int j = 0; j<size; j++){
            afterFactortimesU[j] = factor * getorigU[j];
        }
        utimesfactor.add(afterFactortimesU);
    }
    //initialize yup to 0
    for (int i = 0; i<size; i++){
        yup[i] = 0.0;
    }
    //Calculate yup
    for (int i = 0; i<vectnum; i++){
        double getFactorVector[] = utimesfactor.get(i);
        for (int j = 0; j<size; j++){
            yup[j] += getFactorVector[j];
        }
    }
 
    System.out.print("Yup = ");
    for (int i = 0; i < size; i++) {
        System.out.print(" " +yup[i]);
    }
    System.out.println(" ");
    System.out.print("YminusYup = ");
    for (int i = 0; i < size; i++) {
        yminusyup[i] = y[i] - yup[i];
    }
   for (int i = 0; i < size; i++) {
    yminusyup[i] = RoundtoTheNearest(yminusyup[i], 0.01);
    System.out.print(" " +yminusyup[i]);
    }
    System.out.println(" ");
    double tempnum =0;
    for (int i = 0; i < size; i++) {
        tempnum+=  Math.pow(yminusyup[i], 2.0);;
    }
    System.out.println(tempnum);
   z= Math.sqrt(tempnum);
    System.out.println("Z = " + z);

   
    
    
    
}

}
