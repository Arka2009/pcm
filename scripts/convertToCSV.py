import pandas as pd

PCM_PREFIX=f'/home/arka.maity/Desktop/pcm'
def main():
    coreEventsX=pd.read_json(f'{PCM_PREFIX}/build/bin/ICX/icelakex_core_v1.16.json')
    uncoreEventsX=pd.read_json(f'{PCM_PREFIX}/build/bin/ICX/icelakex_uncore_v1.16.json')
    uncoreExperimentalEventX=pd.read_json(f'{PCM_PREFIX}/build/bin/ICX/icelakex_uncore_v1.16_experimental.json')
    
    excelFileName=f'{PCM_PREFIX}/ICXEvents.xlsx'
    writer = pd.ExcelWriter(excelFileName, engine='xlsxwriter')
    coreEventsX.to_excel(excel_writer=writer,sheet_name='core',index=False)
    uncoreEventsX.to_excel(excel_writer=writer,sheet_name='uncore',index=False)
    uncoreExperimentalEventX.to_excel(excel_writer=writer,sheet_name='uncore-experimental',index=False)
    writer.save()

if __name__=="__main__":
    main()