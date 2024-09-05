def read_tm_file(file_path):
    tm_records = []

    with open(file_path, 'rb') as file:
        while True:
            header = file.read(2)
            if not header:
                break  # конец файла

            parameter_number = int.from_bytes(header, 'big')  # преобразование байтов в число
            if parameter_number == 0xFFFF:
                # это служебное сообщение, пропускаем
                file.seek(30, 1)
            else:
                # это полезная ТМ-запись
                tm_records.append(file.read(14))

    return tm_records


def count_useful_tm_records(file_path):
    useful_tm_count = 0

    with open(file_path, 'rb') as file:
        while True:
            header = file.read(2)
            if not header:
                break  # конец файла

            parameter_number = int.from_bytes(header, 'big')  # преобразование байтов в число
            if parameter_number != 0xFFFF:
                useful_tm_count += 1
                file.seek(14, 1)  # пропустить оставшиеся байты в ТМ-записи

    return useful_tm_count


# Пример использования:
file_path = '190829_v29854.KNP'
useful_tm_count = count_useful_tm_records(file_path)
print(f'Количество полезных ТМ-записей: {useful_tm_count}')
