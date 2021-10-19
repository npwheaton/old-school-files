import java.util.Random;


public class Chromosome {
    private String seta = "";
    private String setb = "";
    private int fitness;
    private double Mchance = 0.0;
    private double Cchance = 0.0;
    private int size;
    private NumberSet nset;
 
 //constructor used for initial population
public Chromosome( NumberSet nset){
    this.nset = nset;
    this.size = this.nset.sendSize();
    populatechromo();
    }
 //constructor used chromosomes made from crossover
 public Chromosome(double chance,double Cchance, NumberSet nset){
     Mchance = chance;
     this.Cchance = Cchance;
     this.nset = nset;
     this.size = this.nset.sendSize();
     }
 //used in 2 point crossover, inherit half of the sets from each parent
 public void inheritance(Chromosome dad, Chromosome mom){
    Random rand = new Random();
     double temp;
     //roll to see if you can Crossbreed the chromosome
     temp = rand.nextDouble();
     if (temp<Cchance){
        seta = dad.PassdownSeta1stHalf() + mom.PassdownSeta2ndHalf();
        setb = dad.PassdownSetb1stHalf() + mom.PassdownSetb2ndHalf(); 
     }
     else
     populatechromo();
    }
 //turns a string to char array, changes the character at specified position, turns array back to string and returns string
 public String SetCharAtPosition(String target, int position, char replacement){
     char[] ch = target.toCharArray();
     ch[position] = replacement;
     String temp = String.valueOf(ch);
     return temp;
     }
 
 public void mutate(){
     Random rand = new Random();
     double temp;
     int temp2;
     //roll to see if you can mutate the chromosome
     temp = rand.nextDouble();
     if (temp<Mchance)
         {//mutate set a and the corresponding position on set b to keep the sets unique
         temp2 = rand.nextInt(seta.length());
         char target = seta.charAt(temp2);
         if (target == '0')
             {seta = SetCharAtPosition(seta, temp2, '1');
             setb = SetCharAtPosition(setb, temp2, '0');
         }
         else
             {seta = SetCharAtPosition(seta, temp2, '0');
             setb = SetCharAtPosition(setb, temp2, '1');
             }
                
         }

     }
 
 public String PassdownSeta1stHalf(){//passes down 1st half of chromosome for set a
     String temp = "";
     for (int i = 0; i<(seta.length()/2); i++)
     {temp+= seta.charAt(i);}
 
     return temp;
     }
 
 public String PassdownSeta2ndHalf(){//passes down 2nd half of chromosome for set a
     String temp = "";
     for (int i = (seta.length()/2)+1; i<seta.length(); i++)
     {temp+= seta.charAt(i);}
     
     return temp;
     }
 public String PassdownSetb1stHalf(){//passes down 1st half of chromosome for set b
     String temp = "";
     for (int i = 0; i<(setb.length()/2); i++)
     {temp+= setb.charAt(i);}
 
     return temp;
     }
 
 public String PassdownSetb2ndHalf(){//passes down 2nd half of chromosome for set b
     String temp = "";
     for (int i = (setb.length()/2)+1; i<setb.length(); i++)
     {temp+= setb.charAt(i);}
         
     return temp;
     }    
 //finds the fitness
 public void calcfitness(){
     int tempa = 0;
     int tempb = 0;
     for (int i = 0; i<seta.length(); i++){
         if (seta.charAt(i)== '1')
             {tempa += nset.Atposition(i);}
         if (setb.charAt(i)== '1')
         {tempb += nset.Atposition(i);}
 
         }
     fitness = Math.abs(tempa-tempb);
     }
 
 //sends fitness value
 public int sendfitness(){ 
     calcfitness();
     return fitness;}
 
//makes the sets unique if for some reason its not.
 public void verifyvalid(){
    for (int i = 0; i<size; i++){
        if (seta.charAt(i)== '0'){
         setb = SetCharAtPosition(setb, i, '1');
         }
         else
         setb = SetCharAtPosition(setb, i, '0');
         }
    }
//populates the chromosome sets
public void populatechromo(){
    Random rand = new Random();
    for (int i = 0; i<this.size; i++){
        int temp;
        temp = rand.nextInt(2);
        if (temp == 0){
         seta+= "0";
         setb+= "1";
         }
         else if (temp == 1){
        seta+= "1";
        setb+= "0";
         }
        }
}
 //tells the contents of sets
 public String toString() {
     String tempa = "";
     String tempb = "";
     for (int i = 0; i<seta.length(); i++){
         if (seta.charAt(i)== '1')
             {tempa += nset.Atposition(i) + " ";}
         if (setb.charAt(i)== '1')
         {tempb += nset.Atposition(i) + " ";}
 
         }
     return "Set A: " + tempa+ "\n Set B: " + tempb;
     }
 }
 
 