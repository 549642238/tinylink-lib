#include "tl_wire.h"

namespace tinylink{
	bool Wire::setConfig(string IP, string netmask, string gateway, vector<string>& dns_nameservers) {
	    if ( "" == IP || "" == netmask || "" == gateway || dns_nameservers.size() == 0){// judge whether ang
	    	printf(" Some configuration is null string!\n");
	    	exit(-1);
	    }
	    FILE *fp;
	    char buf[200];
	    fp = popen("sudo connmanctl services", "r");
	    fgets(buf, sizeof(buf),fp);
	    pclose(fp);
	    string wire_str(buf, strlen(buf));
	    int pos = wire_str.find("ethernet");
	    if (-1 == pos){
	    	perror("Not insert the cable");
	    	exit(-1);
	    }
	    string cable_name = wire_str.substr(pos);
	    string comm = "sudo connmanctl config " + cable_name + " --ipv4 manual " + IP + " " + netmask + " " + gateway + " --nameservers";
	    for(size_t i = 0 ; i != dns_nameservers.size(); i++){
	    	comm = comm + " " + dns_nameservers[i];
	    }
	    int result = system(comm.c_str());
	    if (-1 == result){
	    	perror("Error configuring!");
	    	exit(-1); 
	    }
	    else if( 127 == result ) {
	    	perror("Error calling /bin/sh!");
	    	exit(-1);
	    }
	    else if ( 0 == result) {
	    	cout << "Suceess Configuration!" <<endl;
	    	return 1;
	    }
	    return 0;
    }
}
