package model;

public class Elemento {
	
	private Object dado;
	private Elemento prox;
	private Elemento ant;
	
	public Elemento() {

	}
	
	public Elemento(Object dado) {
		this.dado = dado;
	}
	
	public Elemento(Object dado, Elemento prox) {
		this.dado = dado;
		this.prox = prox;
	}
	
	public Elemento(Object dado, Elemento ant, Elemento prox) {
		this.dado = dado;
		this.ant = ant;
		this.prox = prox;
	}
	
	public Object getDado() {
		return dado;
	}
	
	public void setDado(Object dado) {
		this.dado = dado;
	}
	
	public Elemento getProx() {
		return prox;
	}
	
	public void setProx(Elemento prox) {
		this.prox = prox;
	}
	
	public Elemento getAnt() {
		return ant;
	}
	
	public void setAnt(Elemento ant) {
		this.ant = ant;
	}
	
}
