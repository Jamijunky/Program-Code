import { Client, Databases, Account } from 'appwrite';

export const PROJECT_ID = '6866bcc00003235769ed';
export const DATABASE_ID = '686969b00008bb1a7842';
export const COLLECTION_ID_MESSAGES = '686969c70015f0e21451';

const client = new Client();
client.setEndpoint("https://nyc.cloud.appwrite.io/v1").setProject(PROJECT_ID);

export const databases = new Databases(client);
export const account = new Account(client); 

export default client;
