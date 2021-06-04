theta = {
    'NVB': (None, -25, -40),
    'NB': (-40, -10),
    'N': (-20, 0),
    'ZO': (-5, 5),
    'P': (0, 20),
    'PB': (10, 40),
    'PVB': (25, None, 40)
}


omega = {
    'NB': (None, -3, -8),
    'N': (-6, 0),
    'ZO': (-1, 1),
    'P': (0, 6),
    'PB': (3, None, 8)
}

force = {
    'NVVB': (None, -24, -32),
    'NVB': (-32, -16),
    'NB': (-24, -8),
    'N': (-16, 0),
    'Z': (-4, 4),
    'P': (0, 16),
    'PB': (8, 24),
    'PVB': (16, 32),
    'PVVB': (24, None, 32)
}


fuzzyTable = {
    'PVB': {'PB': 'PVVB', 'P': 'PVVB', 'ZO': 'PVB', 'N': 'PB', 'NB': 'P'},
    'PB': {'PB': 'PVVB', 'P': 'PVB', 'ZO': 'PB', 'N': 'P', 'NB': 'Z'},
    'P': {'PB': 'PVB', 'P': 'PB', 'ZO': 'P', 'N': 'Z', 'NB': 'N'},
    'ZO': {'PB': 'PB', 'P': 'P', 'ZO': 'Z', 'N': 'N', 'NB': 'NB'},
    'N': {'PB': 'P', 'P': 'Z', 'ZO': 'N', 'N': 'NB', 'NB': 'NVB'},
    'NB': {'PB': 'Z', 'P': 'N', 'ZO': 'NB', 'N': 'NVB', 'NB': 'NVVB'},
    'NVB': {'PB': 'N', 'P': 'NB', 'ZO': 'NVB', 'N': 'NVVB', 'NB': 'NVVB'}
}
