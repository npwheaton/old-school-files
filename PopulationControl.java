
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;
public class PopulationControl{
private ArrayList<Chromosome> pop = new ArrayList<Chromosome>();
private int popsize;
private int highfit;
private int avgfit;
private Chromosome highest;

public PopulationControl(int popsize){
    this.popsize = popsize;
    
}

public void generatepopulation(NumberSet nset){
    for (int i = 0; i<popsize; i++){
       
        Chromosome ancestor = new Chromosome(nset);
        insertChromo(ancestor);
    }
}
public void insertChromo(Chromosome chromo) {pop.add(chromo);}

public int sendAvg(){return avgfit;}

public Chromosome SendChromo(){return highest;}

public int sendhigh(){return highfit;}

public void findpopsize(){popsize = pop.size();}

public void FindAvg() {
    int temp = 0;
       for (Iterator<Chromosome> all = pop.iterator(); all.hasNext(); ) {
        Chromosome chromo = (Chromosome) all.next();
        temp+= chromo.sendfitness();
        } 
    findpopsize();
    avgfit= temp/popsize;

    }  

public void findhighfit(){
    int temp = 1000000;
    for (Iterator<Chromosome> all = pop.iterator(); all.hasNext(); ) {
      Chromosome chromo = (Chromosome) all.next();
        if(chromo.sendfitness()<temp)
            {temp = chromo.sendfitness();
             highest = chromo;}
        } 
    highfit = temp;
    }

public void reproduce(double chance, double Cchance, NumberSet nset){
    FindAvg();
    for (Iterator<Chromosome> all = pop.iterator(); all.hasNext(); ) {//remove chromosomes tht are below average
        Chromosome chromo = (Chromosome) all.next();
          if(avgfit<chromo.sendfitness())
              {all.remove();}
        }
    int newpop = pop.size();
    for (int i= 0; i<(popsize-newpop); i++){//replace the deleted chromosomes with new ones
        Random rand = new Random();
        int temp2 = rand.nextInt(newpop);
        Chromosome dad = pop.get(temp2);
        int temp3 = rand.nextInt(newpop);
        Chromosome mom = pop.get(temp3);
        Chromosome child = new Chromosome(chance, Cchance, nset);
        child.inheritance(dad, mom);
        child.mutate();
        insertChromo(child);
        }
    }
    


}