/* STRUKT WARNING : this file has been generated and should not be modified by hand */
#ifndef _paas_environment_c_
#define _paas_environment_c_

#include "element.h"

#include "paas_environment.h"

/*	--------------------------------------------------	*/
/*	l i b e r a t e _ p a a s _ e n v i r o n m e n t 	*/
/*	--------------------------------------------------	*/
public struct paas_environment * liberate_paas_environment(struct paas_environment * sptr)
{
	if ( sptr )
	{
		if ( sptr->id )
			 sptr->id = liberate(sptr->id);
		if ( sptr->name )
			 sptr->name = liberate(sptr->name);
		if ( sptr->uri )
			 sptr->uri = liberate(sptr->uri);
		if ( sptr->config_template )
			 sptr->config_template = liberate(sptr->config_template);
		if ( sptr->date_created )
			 sptr->date_created = liberate(sptr->date_created);
		if ( sptr->date_updated )
			 sptr->date_updated = liberate(sptr->date_updated);
		if ( sptr->description )
			 sptr->description = liberate(sptr->description);
		if ( sptr->provider )
			 sptr->provider = liberate(sptr->provider);
		sptr = liberate( sptr );
	}
	return((struct paas_environment *) 0);

}

/*	--------------------------------------------	*/
/*	r e s e t _ p a a s _ e n v i r o n m e n t 	*/
/*	--------------------------------------------	*/
public struct paas_environment * reset_paas_environment(struct paas_environment * sptr)
{
	if ( sptr )
	{
		sptr->id = (char*) 0;
		sptr->name = (char*) 0;
		sptr->uri = (char*) 0;
		sptr->config_template = (char*) 0;
		sptr->date_created = (char*) 0;
		sptr->date_updated = (char*) 0;
		sptr->description = (char*) 0;
		sptr->provider = (char*) 0;
		sptr->status =  0;
	}
	return(sptr);

}

/*	--------------------------------------------------	*/
/*	a l l o c a t e _ p a a s _ e n v i r o n m e n t 	*/
/*	--------------------------------------------------	*/
public struct paas_environment * allocate_paas_environment()
{
	struct paas_environment * sptr;
	if (!( sptr = allocate( sizeof( struct paas_environment ) ) ))
		return( sptr );
	else	return( reset_paas_environment(sptr) );
}

/*	--------------------------------------------	*/
/*	x m l i n _ p a a s _ e n v i r o n m e n t 	*/
/*	--------------------------------------------	*/
public int xmlin_paas_environment(struct paas_environment * sptr,struct xml_element * eptr)
{
	struct xml_element * wptr;
	if (!( eptr )) return(0);
	if (!( sptr )) return(0);
	for ( wptr=eptr->first; wptr != (struct xml_element *) 0; wptr=wptr->next)
	{
		if (!( strcmp(wptr->name,"id") ))
		{
			if ( wptr->value ) { sptr->id = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"name") ))
		{
			if ( wptr->value ) { sptr->name = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"uri") ))
		{
			if ( wptr->value ) { sptr->uri = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"config_template") ))
		{
			if ( wptr->value ) { sptr->config_template = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"date_created") ))
		{
			if ( wptr->value ) { sptr->date_created = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"date_updated") ))
		{
			if ( wptr->value ) { sptr->date_updated = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"description") ))
		{
			if ( wptr->value ) { sptr->description = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"provider") ))
		{
			if ( wptr->value ) { sptr->provider = allocate_string(wptr->value); }
		}
		else if (!( strcmp(wptr->name,"status") ))
		{
			if ( wptr->value ) { sptr->status = atoi(wptr->value); }
		}
	}
	return(0);

}

/*	----------------------------------------------------	*/
/*	r e s t _ o c c i _ p a a s _ e n v i r o n m e n t 	*/
/*	----------------------------------------------------	*/
public int rest_occi_paas_environment(FILE * fh,struct paas_environment * sptr,char * prefix, char * nptr)
{
	struct xml_element * wptr;
	if (!( sptr )) return(0);
	fprintf(fh,"POST /%s/ HTTP/1.1\r\n",nptr);
	fprintf(fh,"Category: %s; scheme='http://scheme.%s.org/occi/%s#'; class='kind';\r\n",nptr,prefix,prefix);
	fprintf(fh,"X-OCCI-Attribute: %s.%s.id='%s'\r\n",prefix,nptr,(sptr->id?sptr->id:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.name='%s'\r\n",prefix,nptr,(sptr->name?sptr->name:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.uri='%s'\r\n",prefix,nptr,(sptr->uri?sptr->uri:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.config_template='%s'\r\n",prefix,nptr,(sptr->config_template?sptr->config_template:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.date_created='%s'\r\n",prefix,nptr,(sptr->date_created?sptr->date_created:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.date_updated='%s'\r\n",prefix,nptr,(sptr->date_updated?sptr->date_updated:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.description='%s'\r\n",prefix,nptr,(sptr->description?sptr->description:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.provider='%s'\r\n",prefix,nptr,(sptr->provider?sptr->provider:""));
	fprintf(fh,"X-OCCI-Attribute: %s.%s.status='%u'\r\n",prefix,nptr,sptr->status);
	return(0);

}

#endif	/* _paas_environment_cpaas_environment_c_ */