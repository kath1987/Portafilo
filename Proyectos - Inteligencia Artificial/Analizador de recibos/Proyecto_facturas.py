import tkinter as tk
from tkinter import filedialog
import os
import pandas as pd
from pathlib import Path
from azure.core.credentials import AzureKeyCredential
from azure.ai.formrecognizer import DocumentAnalysisClient
import tkinter as tk
from tkinter import filedialog 

df=pd.DataFrame(); #se crea ek datafrae vacio y se almacena en df

endpoint = "https://melon.cognitiveservices.azure.com/"
key = "65d700c4332d4e29b0866d49237b17af"

model_id = "factura_modelo"

document_analysis_client = DocumentAnalysisClient(
    endpoint=endpoint, credential=AzureKeyCredential(key)
)

bill_path = "C:\\Users\\kater\\Desktop\\ITLA\\PROYECTO FERIA CIENTIFICA NLTK\\New folder\\factura"
a=0
for i in range(800):
    int(a)
    a+=1
    b= str(a)
    print(bill_path + " (" + b + ").pdf")
    direccion =bill_path + " (" + b + ").pdf"

    # Analizar el documento seleccionado

    with open(direccion, "rb") as f:

        poller = document_analysis_client.begin_analyze_document(model_id, document=f.read())


    # extraer los campos analizados
    result = poller.result()
    

    # Extraer los campos analizados y escribirlos en archivo csv

    df = pd.DataFrame()

    for idx, document in enumerate(result.documents):

        

        # print("Tipo de documento: {}".format(document.doc_type))

        # print("confidence: {}".format(document.confidence))

        # print("Documento analizado por el modelo: {}".format(result.model_id))

        # print("new dataframe:  {}" .format(df))

        for name, field in document.fields.items():

            campos = field.value if field.value else field.content

            df[name] = [field.value]

            # print("campo encontrado : {}".format(name))

        df.to_csv("resultados.csv", mode='a', header=False, index=False)


    print("proceso finalizado")

            
