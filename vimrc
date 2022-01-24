call plug#begin()
Plug 'tpope/vim-fugitive'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'fatih/vim-go'
Plug 'kien/ctrlp.vim'
Plug 'honza/vim-snippets'
Plug 'lervag/vimtex'
Plug 'othree/javascript-libraries-syntax.vim'
Plug 'valloric/matchtagalways'
Plug 'jeetsukumaran/vim-buffergator'
Plug 'eagletmt/neco-ghc'
Plug 'python-mode/python-mode'
Plug 'matze/vim-move'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'puremourning/vimspector'
call plug#end()

:set tabstop=3
:set shiftwidth=3
:set relativenumber
:set expandtab
:tnoremap <Esc> <C-\><C-n>

" mnemonic 'di' = 'debug inspect' (pick your own, if you prefer!)
" for normal mode - the word under the cursor
nmap <Leader>di <Plug>VimspectorBalloonEval
" for visual mode, the visually selected text
xmap <Leader>di <Plug>VimspectorBalloonEval

set noshowmode
if !exists('g:airline_symbols')
let g:airline_symbols = {}
endif
" unicode symbols
let g:airline_left_sep = '»'
let g:airline_left_sep = 'arrow_forward'
let g:airline_right_sep = '«'
let g:airline_right_sep = 'arrow_backward'
let g:airline_symbols.linenr = '☰'
let g:airline_symbols.paste = 'ρ'
let g:airline_symbols.paste = 'Þ'
let g:airline_symbols.notexists = '∄'
let g:airline_symbols.whitespace = 'Ξ'

" powerline symbols
let g:airline_left_sep = ''
let g:airline_left_alt_sep = ''
let g:airline_right_sep = ''
let g:airline_right_alt_sep = ''
let g:airline_symbols.branch = ''
let g:airline_symbols.readonly = ''
let g:airline_symbols.linenr = ' ☰ '
let g:airline_symbols.maxlinenr = ' '
