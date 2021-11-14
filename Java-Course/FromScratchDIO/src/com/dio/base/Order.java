package com.dio.base;

import java.math.BigDecimal;

/**
 * Represent an order
 * 
 * @author Ailton
 * @version 1.0.0
 * @see BigDecimal
 * @since Release 1.0.0
*/
public class Order {
	private final String code;
	private final BigDecimal totalValue;

	/**
	 * Construct of the class
	 * 
	 * @param code			Code of the order
	 * @param totalValue	Total amount of order
	 */
	public Order(String code, BigDecimal totalValue) {
		this.code = code;
		this.totalValue = totalValue;
	}

	/**
	 * Calculate tax based on total value of order
	 * 
	 * @return					total value with tax
	 * @throws RuntimeException	If value is negative
	 */
	public BigDecimal calculateFee() throws RuntimeException {
		if(this.totalValue.signum() < 0) {
			throw new RuntimeException("Value cant be negative!");
		}
		if(this.totalValue.compareTo(new BigDecimal("100.00")) > 100) {
			this.totalValue.multiply(new BigDecimal("0.99"));
		}
		return this.totalValue;
	}

	@Override
	public String toString() {
		return "Order={code='"+code+"'}";
	}
}
