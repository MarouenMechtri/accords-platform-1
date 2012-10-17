package org.ow2.compatibleone;

public abstract class Procci {
	/* All this methods must return a json String. Its format is user defined
	 * but it must match the definitions in the C layer. */
	public abstract String start_server(Object[] args) throws Exception;
	public abstract String stop_server(Object[] args) throws Exception;
	public abstract String monitor_server(Object[] args) throws Exception;
	public abstract String list_servers(Object[] args) throws Exception;
}