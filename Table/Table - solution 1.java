

public class Table {
	int _taille;
	Object _baguettes[];
	int nbPersonnes;
	
	Table(int t) {
		_taille = t;
		_baguettes = new Object[_taille];
		for (int i = 0; i < _taille; i++) {
			_baguettes[i]= new Object();
		}
	}
	
	void prendreBaguettes(int i) throws InterruptedException {
	    // TODO

		synchronized(this){

			while(nbPersonnes == _taille - 1){
				this.wait();
			}
			nbPersonnes++;
			
		}
		synchronized(_baguettes[i]){

		    System.out.println("J'ai une baguette "+ i);
		    
		    Thread.sleep(100);

		    synchronized(_baguettes[(i+1)%_taille]){

			    System.out.println("Je mange "+ i);

			    Thread.sleep(5000);

			}
		}
		synchronized(this){
			nbPersonnes--;
			notify();
		}
	}	
}
