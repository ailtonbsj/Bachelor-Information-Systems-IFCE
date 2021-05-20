package br.edu.ifce.sysinfo.ailtonbsj;

public class ContaBanco {
	
	public int numConta;
	protected TipoDeConta tipo;
	private String dono;
	private double saldo;
	private boolean enabled;
	private double limite;
	
	private void contaDesativadaAlerta() {
		System.out.println("Operação não permitida! Conta está desativada!");
	}
	
	public TipoDeConta getTipo() {
		return tipo;
	}
	
	public void setTipo(TipoDeConta tipo) {
		if(isEnabled()) this.tipo = tipo;
		else contaDesativadaAlerta();
	}
	
	public String getDono() {
		return dono;
	}
	
	public void setDono(String dono) {
		if(isEnabled()) this.dono = dono;
		else contaDesativadaAlerta();
	}
	
	public double getSaldo() {
		return saldo;
	}
	
	private void setSaldo(double saldo) {
		this.saldo = saldo;
	}
	
	public boolean isEnabled() {
		return enabled;
	}
	
	private void setEnabled(boolean status) {
		this.enabled = status;
	}
	
	public double getLimite() {
		return limite;
	}
	
	public void setLimite(double valor) {
		if(isEnabled())
			this.limite = valor;
		else contaDesativadaAlerta();
	}
	
	public void abrirConta() {
		this.setEnabled(true);
	}
	
	public void fecharConta() {
		if(this.getSaldo() > 0)
			System.out.println("Operação não possível! Ainda há saldo!");
		else if(this.getSaldo() < 0)
			System.out.println("Operação não possível! Saldo negativo!");
		else this.setEnabled(false);
	}
	
	public void depositar(double valor) {
		if(isEnabled())
			this.setSaldo(this.getSaldo() + valor);
		else contaDesativadaAlerta();
	}
	
	public void sacar(double valor) {
		double valorRestante = this.getSaldo() - valor;
		if(isEnabled())
			if(valorRestante >= -getLimite())
				this.setSaldo(valorRestante);
			else System.out.println("Impossível Sacar esse valor! Limite excedido!");
		else contaDesativadaAlerta();
	}
	public void pagarMensal(double valor, String desc) {
		if(isEnabled()) {
			this.sacar(valor);
			System.out.println("Pagamento mensal: " + valor + " ( " + desc + " )");
		}
		else contaDesativadaAlerta();
	}
	
	public ContaBanco(int numConta, String nome) {
		this.numConta = numConta;
		this.setEnabled(true);
		this.setTipo(TipoDeConta.CORRENTE);
		this.setDono(nome);
		this.setEnabled(false);
	}
	
}