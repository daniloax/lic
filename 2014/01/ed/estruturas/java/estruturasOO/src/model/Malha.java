package model;

import java.util.Random;

public class Malha implements Estrutura {
	
	private Elemento no;
	
	public Malha() {

	}
	
	public Elemento getNo() {
		return no;
	}
	
	public void setNo(Elemento no) {
		this.no = no;
	}

	@Override
	public void construir() {
		
		Elemento no_a, no_b, no_c, no_d;
		Random randomNumbers;
		int valorCaracter;
		
		no_b = new Elemento();
		no_d = new Elemento();
		randomNumbers = new Random();
		
		for (int i = 0; i < 20; i++) {
			
			valorCaracter = 64 + randomNumbers.nextInt(22);
			
			if ((valorCaracter == 65) || (valorCaracter == 69) || (valorCaracter == 73) || (valorCaracter == 79) || (valorCaracter == 85)) {

				no_a = new Elemento((char) valorCaracter, null);
				
				if (this.getNo() == null)
					this.setNo(no_a);
				
				else
					no_b.setProx(no_a);
				
				no_b = no_a;
				
				for (int j = 0; j < 10; j++) {
					
					valorCaracter = 65 + randomNumbers.nextInt(22);
					
					if ((valorCaracter == 65) || (valorCaracter == 69) || (valorCaracter == 73) || (valorCaracter == 79) || (valorCaracter == 85)) {
						
						no_c = new Elemento((char) valorCaracter, null);
						
						if (no_a.getAnt() == null)
							no_a.setAnt(no_c);
						
						else
							no_d.setProx(no_c);
						
						no_d = no_c;
						
						
					}
				
				}
				
			}				
			
		}
		
		no_b.setProx(null);
		
	}

	@Override
	public void inserir(Object dado) {
		// TODO Auto-generated method stub

	}

	@Override
	public boolean procurar(Object dado) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public Object raiz() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object remover() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void remover(Object dado) {
		// TODO Auto-generated method stub

	}

	@Override
	public void ler() {

		Elemento no_a, no_b;
		
		no_a = this.getNo();
		
		if (no_a == null)
			System.out.printf("malha vazia\n");
		
		else {
			
			System.out.println();
			
			while (no_a != null) {
				
				System.out.printf("|-- %c\n", no_a.getDado());
				no_b = no_a.getAnt();

				while (no_b != null) {
					
					System.out.printf("    |-- %c\n", (char) no_b.getDado());
					no_b = no_b.getProx();
					
				}
				
				System.out.println();				
				no_a = no_a.getProx();
				
			}
		
		}
		
		System.out.println();

	}

}
