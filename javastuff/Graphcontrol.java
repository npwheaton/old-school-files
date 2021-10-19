import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;
public class Graphcontrol{
private ArrayList<Graphmosome> graphpop = new ArrayList<Graphmosome>();
private int graphpopsize;
private int highfit;
private int avgfit;
private Graphmosome highest;
private Graphset gset;

public Graphcontrol(int graphpopsize, Graphset gg){
    this.graphpopsize = graphpopsize;
    gset = gg;
    
}

public void generatepopulation(){
    for (int i = 0; i<graphpopsize-3; i++){
       
        Graphmosome ancestor = new Graphmosome(gset);
        insertgraph(ancestor);
    }
    seed();
}
public void insertgraph(Graphmosome graph) {graphpop.add(graph);}

public int sendAvg(){return avgfit;}

public Graphmosome Sendgraph(){return highest;}

public int sendhigh(){return highfit;}

public void findgraphpopsize(){graphpopsize = graphpop.size();}

public void FindAvg() {
    int temp = 0;
       for (Iterator<Graphmosome> all = graphpop.iterator(); all.hasNext(); ) {
        Graphmosome graph = (Graphmosome) all.next();
        temp+= graph.sendfitness();
        } 
    avgfit= temp/graphpop.size();

    }  

public void findhighfit(){
    int temp = 1000000;
    for (Iterator<Graphmosome> all = graphpop.iterator(); all.hasNext(); ) {
      Graphmosome graph = (Graphmosome) all.next();
        if(graph.sendfitness()<temp)
            {temp = graph.sendfitness();
            highfit = temp;
            highest = graph;}
        } 
    }
public void disqualifybadgraphs(){
    for (Iterator<Graphmosome> all = graphpop.iterator(); all.hasNext(); ) {//remove Graphmosomes tht are below average
        Graphmosome gh = (Graphmosome) all.next();
          if(!gh.isConnected())
              {all.remove();}
        else if (gh.HasCycle())
            {all.remove();}
        }
}
public void reproduce(double chance, double Cchance){
    FindAvg();
    findhighfit();
    for (Iterator<Graphmosome> pop = graphpop.iterator(); pop.hasNext(); ) {//remove Graphmosomes tht are below average
        Graphmosome bad = (Graphmosome) pop.next();
          if(avgfit<bad.sendfitness())
              {pop.remove();}
        }
    int newgraphpop = graphpop.size();
    for (int i= 0; i<(graphpopsize-newgraphpop); i++){//replace the deleted Graphmosomes with new ones
        Random rand = new Random();
        int temp2 = rand.nextInt(newgraphpop);
        Graphmosome dad = graphpop.get(temp2);
        int temp3;
        do{
         temp3 = rand.nextInt(newgraphpop);
        }while(temp2==temp3);
        Graphmosome mom = graphpop.get(temp3);
        Graphmosome child = new Graphmosome(chance, Cchance, gset);
        child.inheritance(dad, mom);
        child.mutate();
        insertgraph(child);
        }
    }
    
public void seed(){
    Graphmosome seed1 = new Graphmosome(gset);
    Graphmosome seed2 = new Graphmosome(gset);
    Graphmosome seed3 = new Graphmosome(gset);
    seed1.spiderwebseed();
    seed2.snakeseed();
    seed3.bintreeseed();
    insertgraph(seed1);
    insertgraph(seed2);
    insertgraph(seed3);     
}

}
