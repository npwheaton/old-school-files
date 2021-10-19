public class NumberSet{
private int size;
private int nset[];

public NumberSet(int Nsize){
    size = Nsize;
    nset = new int[size];
    }
public void populateSet(){
    for (int i= 0; i<size; i++)
        {nset[i]= i;}
    }
public int Atposition(int num){
        return nset[num];
    }
public int sendSize(){
    return size;
    }
public String toString(){
    String temp = "";
    for(int i = 0; i<nset.length; i++){
        temp+= nset[i]+ " ";
        }
    return temp;
    }
}
